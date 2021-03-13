#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

#define TIMER2_OCR        62                       // count 62 ticks
#define TIMER2_PRESCALER ((1<<CS22) | (1 << CS20)) // divide by 128

void delay_ms(uint16_t n);

#endif
