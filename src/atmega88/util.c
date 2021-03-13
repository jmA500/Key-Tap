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
  OCR2A  = TIMER2_OCR;
  TCCR2A |= (1<<WGM21);
  TCCR2B |= TIMER2_PRESCALER;
  TIMSK2 |= (1 << OCIE2A);
}

void delay_ms(uint16_t n)
{
  time_base = n;
  
  do
    {}
  while (time_base);
}

ISR(TIMER2_COMPA_vect)
{
  if (time_base)
    time_base--;

#ifdef UTIL_SYS_TIME
  util_time_cnt++;  
#endif
}
