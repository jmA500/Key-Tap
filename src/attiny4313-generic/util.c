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

#include "util.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

volatile static uint16_t time_base;

static void util_init3(void) __attribute__ ((naked, used, section (".init3")));

/* !!! never call this function !!! */
static void util_init3 (void)
{
  OCR1A  = TIMER1_OCR;
  TCCR1B |= (1<<WGM12) | TIMER1_PRESCALER;
  TIMSK  |= (1 << OCIE1A);
}

void delay_ms(uint16_t n)
{
  time_base = n;
  
  do
    {}
  while (time_base);
}

ISR(TIMER1_COMPA_vect)
{
  if (time_base)
    time_base--;
}
