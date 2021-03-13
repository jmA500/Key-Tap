/************************************************************************
Title:    Some trivial helper functions for working with the uart.

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

#include "uart_helper.h"
#include "uart.h"

uint8_t digit_to_hex(uint8_t digit)
{
  if (digit < 10)
    digit += '0';
  else
    digit += ('A'-10);
  return digit;
}

void uart_put_hex(uint8_t n)
{
  uart_putc(' ');
  uart_putc(digit_to_hex(n/16));
  uart_putc(digit_to_hex(n%16));
}

void uart_put_newline()
{
  uart_putc('\n');
}

void uart_put_hexnl(uint8_t n)
{
  uart_put_hex(n);
  uart_put_newline();
}

uint8_t hexctoi(char c)
{
  if (('0' <= c) && (c <= '9'))
    return c-'0';
  else if (('a'<= c) && (c <= 'f'))
    return c - 'a' + 10;
  else if (('A'<= c) && (c <= 'F'))
    return c - 'A' + 10;

  return 255;
}

void uart_wait_free()
{
  while (uart_tx_char_present());
}
