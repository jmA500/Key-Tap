/************************************************************************
Title:    Some trivial helper functions for working with the uart.

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

#ifndef UART_HELPER_H
#define UART_HELPER_H

#include <stdint.h>
#include "uart.h"

void uart_put_hex(uint8_t n);
void uart_put_newline();
void uart_put_hexnl(uint8_t n);
uint8_t hexctoi(char c);

#if  UART_DEBUG>0
#define uart_dbg(STR) uart_puts_P(STR)
#define uart_dbg_hex(VAL) uart_put_hex(VAL)
#define uart_dbg_hexnl(VAL) uart_put_hexnl(VAL)
#define uart_dbg_newline() uart_put_newline()
#else
#define uart_dbg(STR)
#define uart_dbg_hex(STR)
#define uart_dbg_hexnl(VAL)
#define uart_dbg_newline()
#endif

#endif
