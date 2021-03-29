/************************************************************************
Title:    Main file for the firmware of an Amiga 500 Configurator. 
          Listens to the keyboard and takes keypresses to configure the 
          Amiga via some pins of the MCU.

Author:   Jan Metzger <jm@metweb.de>

License:  GNU General Public License 

LICENSE:
    Copyright (C) 2014-2021 Jan Metzger

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include <ctype.h>
#include "key_tap.h"
#include "util.h"
#include "uart.h"
#include "ee_helper.h"

#define UART_DEBUG 1
#include "uart_helper.h"

#define CONFIG_PORT0 PORTD
#define CONFIG_DDR0  DDRD
#define CONFIG_BIT0  PD6

#define CONFIG_PORT1 PORTB
#define CONFIG_DDR1  DDRB
#define CONFIG_BIT1  PB1
 
#define CONFIG_PORT2 PORTB
#define CONFIG_DDR2  DDRB
#define CONFIG_BIT2  PB3 

#define CONFIG_PORT3 PORTD
#define CONFIG_DDR3  DDRD
#define CONFIG_BIT3  PD4 

#define CONFIG_PORT4 PORTB
#define CONFIG_DDR4  DDRB
#define CONFIG_BIT4  PB0
 
#define CONFIG_PORT5 PORTB
#define CONFIG_DDR5  DDRB
#define CONFIG_BIT5  PB2 
 
#define CONFIG_PORT6 PORTB
#define CONFIG_DDR6  DDRB
#define CONFIG_BIT6  PB4

#define CONFIG_PORT7 PORTD
#define CONFIG_DDR7  DDRD
#define CONFIG_BIT7  PD5

/* The timing for the key presses for the RGBtoHDMI  
 * Key press lengths for short and long presses in ms */
#define BUTTON_SHORT 100
#define BUTTON_LONG  1400
#define BUTTON_VERY_LONG 10000

#define SET_BIT_TRI(PORT,DDR,BIT,STATE) { \
    if (STATE) \
      { (PORT) &= ~(1<<(BIT)); (DDR) |= (1<<(BIT)); } \
    else \
      { (DDR) &= ~(1<<(BIT)); } }

/* 
   The following variables store the current config. 
   Every bit corresponds to a config pin.
   Note that the interpretation is 'negative logic':
     1 means that the pin is pulled low (i.e. jumper on)
     0 means that the pin is high-z (i.e. jumper off)
*/
static struct
{
  uint8_t current;
  uint8_t next;
} conf;

void set_config()
{
  conf.current = conf.next;
  SET_BIT_TRI(CONFIG_PORT0, CONFIG_DDR0, CONFIG_BIT0, conf.current & (1<<0));
  SET_BIT_TRI(CONFIG_PORT1, CONFIG_DDR1, CONFIG_BIT1, conf.current & (1<<1));
  SET_BIT_TRI(CONFIG_PORT2, CONFIG_DDR2, CONFIG_BIT2, conf.current & (1<<2));
  SET_BIT_TRI(CONFIG_PORT3, CONFIG_DDR3, CONFIG_BIT3, conf.current & (1<<3));
  SET_BIT_TRI(CONFIG_PORT4, CONFIG_DDR4, CONFIG_BIT4, conf.current & (1<<4));
  SET_BIT_TRI(CONFIG_PORT5, CONFIG_DDR5, CONFIG_BIT5, conf.current & (1<<5));
  SET_BIT_TRI(CONFIG_PORT6, CONFIG_DDR6, CONFIG_BIT6, conf.current & (1<<6));

#ifdef UART_DEBUG  
  uart_dbg("CFG Set");
  uart_dbg_hexnl(conf.current);
#endif
  delay_ms(500);
}

inline void init()
{
  sei();
#ifdef UART_DEBUG  
  uart_init();
  uart_dbg("KEYTAP Generic RGB v1.1 JM 2021\n");
#endif
  kbd_init();
}

void uart_print_next()
{
#ifdef UART_DEBUG
  uart_dbg("CFG next");
  uart_dbg_hexnl(conf.next);
#endif
}

void uart_print_current()
{
#ifdef UART_DEBUG
  uart_dbg("CFG now");
  uart_dbg_hexnl(conf.current);
#endif
}

inline void uart_print_help()
{
#ifdef UART_DEBUG
  uart_puts_P("Commands\nh : help\n? : Show\n");
  uart_puts_P("! xx : Set config to hex value xx\n");
  uart_puts_P("d : dump eeprom\n");
  uart_puts_P("res : reset\n");
#endif
}

inline void uart_print_err()
{
#ifdef UART_DEBUG
  uart_dbg("Error\n");
#endif
}

inline void uart_print_fkey(uint8_t lastfkey)
{
#ifdef UART_DEBUG
  uart_dbg("KEY reg F");
  uart_dbg_hexnl(lastfkey);
#endif
}

inline void pull_key(uint16_t delay)
{
  SET_BIT_TRI(CONFIG_PORT7, CONFIG_DDR7, CONFIG_BIT7, 1);
  delay_ms(delay);
  SET_BIT_TRI(CONFIG_PORT7, CONFIG_DDR7, CONFIG_BIT7, 0);    
}

/* Parse input from UART. Format is simple but rigid, see uart_print_help() */
void parse (char* str)
{
  switch (str[0])
    {
    case '?':
      uart_print_next();
      uart_print_current();
      break;
    case 'h':
      uart_print_help();
      break;
    case 'd':
      dump_eeprom();
      break;
    case '!':
      {
	uint8_t pos = 1;
	uint8_t resa,resb;

	while (str[pos]==' ')
	  { pos++; }

	resa = hexctoi(str[pos]);
	if (resa != 255)
	  {
	    resb = hexctoi(str[pos+1]);
	    if (resb != 255)
	      {
		conf.next = (resa<<4) + resb;
		uart_print_next();
	      }
	    else
	      {
		uart_print_err();
	      }
	  }
	else
	  {
	    uart_print_err();
	  }
      }
      break;
    case 'r':
      if ((str[1] == 'e') && (str[2] == 's'))
	{
	  kbd_do_reset();
	  set_config();
	  ee_save_config(conf.current);
	  kbd_do_reset();
	}
      break;
    }
}

#define UARTBUF 16
void check_uart()
{
#ifdef UART_DEBUG
  static char buf[UARTBUF];
  static uint8_t bufpos = 0;

  if (uart_rx_char_present())
    {
      char res = uart_getc();
      switch (res)
	{
	case '\r':
	case '\n':
	  buf[bufpos] = 0;
	  parse(buf);
	  bufpos = 0;
	  break;
	case '\b':
	  if (bufpos)
	    bufpos--;
	  break;
	default:
	  if (bufpos < UARTBUF - 1)
	    {
	      buf[bufpos] = res;
	      bufpos++;
	    }
	}
    }
#endif 
}

#define SHIFT_FLAG 1
#define HELP_FLAG  2
#define DEL_FLAG   4

int __attribute__((OS_main))
main()
{
  init();
  conf.next = ee_load_config();
  set_config();
  delay_ms(200);
  
  uint8_t res;
  uint8_t lastfkey = 0;
  uint8_t help_cnt = 0;
  uint8_t del_cnt = 0;
  uint8_t flags = 0;

  for (;;)
    {
      check_uart();

      if (kbd_get_key(&res))
	{
	  /* The keycode is in the upper seven bits, push/release in the LSB, 
	     LSB = 0 if key is pressed, LSB = 1 if released*/
	  uint8_t code = res >> 1;
	  uint8_t push = (~res & 0x01);

	  /* This is the code that decides what to do if a keypress is detected.
	     Note that it also keeps track whether shift, help and del are active or not */
	  if (push)
	    {
	      if (code == KEY_HELP)
		{
		  flags |= HELP_FLAG;
		  help_cnt++;
		  if (help_cnt == 3)
		    {
		      if (lastfkey)
			{
			  uint8_t next = conf.next;
			  if ( (0 < lastfkey) && (lastfkey <= 7) )
			    {
			      next |= (1 << (lastfkey-1));
			    }
			  else if ( (11 <= lastfkey) && (lastfkey <= 17))
			    {
			      next &= ~(1 << (lastfkey - 11));
			    }
			  conf.next = next;
			  uart_print_next();
			}
		      else
			{
			  uart_dbg("CFG no F before HELP\n");
			}
		    }
		}
	      else
		{
		  help_cnt = 0;
		  lastfkey = 0;
		}

	      if (code == KEY_DELETE)
		{
		  flags |= DEL_FLAG;
		  del_cnt++;
		  if (del_cnt == 3)
		    {
		      uart_print_current();
		      uart_print_next();
		    }
		}
	      else
		{
		  del_cnt = 0;
		}

	      if ((KEY_F1 <= code) && (code <= KEY_F7))
		{
		  lastfkey = code - KEY_F1 +1;
		  if (flags & SHIFT_FLAG)
		    lastfkey += 10;
		  uart_print_fkey(lastfkey);
		}

	      if (code == KEY_F9)
		{
		  if ( flags & HELP_FLAG )
		    {
#ifdef UART_DEBUG
		      uart_dbg(".");
#endif
		      pull_key(BUTTON_SHORT);
		    }
		}

	      if (code == KEY_F10)
		{
		  if ((flags & HELP_FLAG) && (flags & SHIFT_FLAG))
		    {
#ifdef UART_DEBUG
		      uart_dbg("O");
#endif
		    pull_key(BUTTON_VERY_LONG);
		    }
		  else if ( flags & HELP_FLAG )
		    {
#ifdef UART_DEBUG
		      uart_dbg("o");
#endif
			
		      pull_key(BUTTON_LONG);
		    }
		}
	      
	      if ((code == KEY_SHIFTL) || (code == KEY_SHIFTR))
		{
		  flags |= SHIFT_FLAG;
		}
	    }
	  else /* Unset pushed flags if key is released */
	    {
	      switch (code)
		{
		case KEY_SHIFTL:
		case KEY_SHIFTR:
		  flags &= ~SHIFT_FLAG;
		  break;
		case KEY_DELETE:
		  flags &= ~DEL_FLAG;
		  break;
		case KEY_HELP:
		  flags &= ~HELP_FLAG;
		  break;
		default:
		  break;
		}
	    }
	}

      if (kbd_got_reset())
      	{
	  uart_dbg("RESET\n");
      	  set_config();
	  ee_save_config(conf.current);
	  delay_ms(400);
      	}
      
      if (kbd_got_long_reset())
	{
	  conf.next = CONFIG_DEFAULT;
      	  set_config();
	  ee_save_config(conf.current);
	}
    }

  return 0;
}
