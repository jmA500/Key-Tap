/************************************************************************
Title:    Interrupt UART library with receive/transmit circular buffers

Original Author:   Peter Fleury <pfleury@gmx.ch>
Modified by:       Jan Metzger <jm@metweb.de>

License:  GNU General Public License 

LICENSE:
    Copyright (C) 2006 Peter Fleury
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

#ifndef UART_H
#define UART_H

#include <avr/pgmspace.h>

#define UART_BAUD_RATE  19200UL
#define UART_BUFSIZE    64

typedef struct 
{ 
  char    buffer[UART_BUFSIZE];
  uint8_t readpos;
  uint8_t writepos;
} uart_buffer_t;

extern volatile uart_buffer_t uart_rx_buffer;
extern volatile uart_buffer_t uart_tx_buffer;

void uart_init();
void uart_clear_rx_buffer();

void uart_putc(char b);
void uart_puts(const char* str);
void uart_puts_p(const char* PROGMEM s);

uint8_t uart_rx_char_present();
uint8_t uart_tx_char_present();

char uart_getc();
void uart_gets(char* str, char delim);

#define uart_puts_P(__s)         uart_puts_p(PSTR(__s))

#endif
