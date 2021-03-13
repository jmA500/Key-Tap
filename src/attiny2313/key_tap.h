/************************************************************************
Title:    Amiga Keyboard listener and decoder functions

Author:   Jan Metzger <jm@metweb.de>

License:  GNU General Public License 

LICENSE:
    Copyright (C) 2014 Jan Metzger

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
************************************************************************/

#ifndef KEY_TAP_H
#define KEY_TAP_H

#include <stdint.h>
#include <avr/io.h>

/* These variables configure the timer for timeout. 
   The timer should trigger every 40 us, and 
   TIMELEFT_INIT gives the numer of timer cycles per 
   bit before reading a byte from the keyboard 
   is canceled */
#define TIMER0_OCR     25
#define TIMELEFT_INIT  7
#define TIME_RESET     256-20

/* Configure the Pins here */
#define KBD_DATA_PIN  PINA
#define KBD_DATA_BIT  PA0 

#define KBD_RESET_PIN  PINA
#define KBD_RESET_PORT PORTA
#define KBD_RESET_DDR  DDRA
#define KBD_RESET_BIT PA1 

/* Keycodes */
#define KEY_F1     0x50
#define KEY_F10    0x59
#define KEY_HELP   0x5f
#define KEY_SHIFTL 0x60 
#define KEY_SHIFTR 0x61
#define KEY_DELETE 0x46

#define KBD_FLAG_KEY_AVAILABLE 0x01
#define KBD_FLAG_GOT_RESET     0x02

typedef struct 
{
  uint8_t data;
  uint8_t flags;
} kbd_ctl_t;

extern volatile kbd_ctl_t kbd_ctl;

/* Initialize keyboard functions. */
void kbd_init();

/* Returns 1 if a key press is detected, then the argument holds the keycode.
   Returns 0 otherwise and leaves argument unchanged. */
uint8_t kbd_get_key(uint8_t* res);

/* Check flags for reset */
uint8_t kbd_got_reset();

/* Reset the Amiga via Kbd_reset */
void    kbd_do_reset();
 
#endif
