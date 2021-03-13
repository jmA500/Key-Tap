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

void uart_put_hex(uint8_t n)
{
  uart_putc(' ');
  uint8_t digit = n/16;
  if (digit < 10)
    uart_putc(digit + '0');
  else
    uart_putc(digit + 'A' -10);

  digit = n % 16;
  if (digit < 10)
    uart_putc(digit + '0');
  else
    uart_putc(digit + 'A' -10);
}

void uart_put_newline()
{
  uart_putc('\n');
}

uint8_t hexctoi(char c)
{
  if (isdigit(c))
    return c-'0';
  else if (('a'<= c) && (c <= 'f'))
    return c - 'a' + 10;
  else if (('A'<= c) && (c <= 'F'))
    return c - 'A' + 10;

  return 255;
}
