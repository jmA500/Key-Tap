#ifndef UART_H
#define UART_H

#include <avr/pgmspace.h>

#define UART_BAUD_RATE  9600UL
#define UART_BUFSIZE    32

// configure which uart to use if there is more than one
#define UART_USEUART 0

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
