#ifndef KEY_TAP_H
#define KEY_TAP_H

#include <stdint.h>
#include <avr/io.h>

#define TIMER0_OCR    25
#define TIMEOUT_INIT  7
#define TIME_RESET    256-20

#define KBD_DATA_PIN  PIND
#define KBD_DATA_BIT  PD3  /* Correct later */

#define KBD_RESET_PIN  PIND
#define KBD_RESET_PORT PORTD
#define KBD_RESET_DDR  DDRD
#define KBD_RESET_BIT PD4  /* Correct later */

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

inline void    kbd_init()
{
  /* Timer0: Set CTC Mode, select main clock for timer, enable interrupt */
  TCCR0A |= (1<<WGM01);
  TCCR0B |= (1<<CS01);
  OCR0A = TIMER0_OCR;
  TIMSK0 |= (1 << OCIE0A);

  /* Interrupt 0: Triggers when CKL transitions to low, enable interrupt */
  EICRA |= (1<<ISC01);
  EIMSK |= (1<<INT0);

  // kbd_ctl.flags = 0;
}

uint8_t kbd_get_key(uint8_t* res);
uint8_t kbd_got_reset();
void    kbd_do_reset();
 
#endif
