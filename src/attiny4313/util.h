/************************************************************************
Title:    A delay function using a timer.

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

#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

/* The timer should be configured such that it triggers once per ms */
#define TIMER1_OCR        125                      // count 125 ticks
#define TIMER1_PRESCALER ((1<<CS11) | (1 << CS10)) // divide by 64

void delay_ms(uint16_t n);

#endif
