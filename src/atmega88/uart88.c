#include "uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#define UART_UBRR       ((F_CPU+UART_BAUD_RATE*8)/(UART_BAUD_RATE*16)-1)
#define UART_BAUD_REAL  (F_CPU/(16*(UART_UBRR+1)))
#define UART_BAUD_ERROR ((UART_BAUD_REAL*1000)/UART_BAUD_RATE) 
 
#if ((UART_BAUD_ERROR<990) || (UART_BAUD_ERROR>1010))
  #error Baud Rate error too high
#endif

volatile uart_buffer_t uart_rx_buffer;
volatile uart_buffer_t uart_tx_buffer;

void uart_init()
{
  // enable RX, TX, RX interrupt
  UCSR0B |= (1<<TXEN0) | (1 << RXEN0) | (1 << RXCIE0);
  
  // 8 data bits
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
  
  // set baudrate
  UBRR0H = UART_UBRR >> 8;
  UBRR0L = UART_UBRR & 0xFF;
}

void uart_clear_rx_buffer()
{
  uint8_t sreg_save = SREG;
  cli();      
  
  uart_rx_buffer.readpos = 0;
  uart_rx_buffer.writepos = 0;

  SREG = sreg_save;
}

void uart_putc(char c)
{
  uint8_t sreg_save = SREG;
  cli();

  if (UCSR0A & (1<<UDRE0))
    // transmitter free, transmit
    {
      UDR0 = c;
    }
  else
    // transmitter busy, write to buffer, enable interrupt
    {
      uint8_t tmp = uart_tx_buffer.writepos;
      uart_tx_buffer.buffer[tmp] = c;
      tmp++;
      tmp &= (UART_BUFSIZE-1);
      uart_tx_buffer.writepos = tmp;

      UCSR0B |= (1 << UDRIE0);
    }
  SREG = sreg_save;
}

void uart_puts (const char *s)
{
  while (*s)
    {
      uart_putc(*s);
      s++;
    }
}

void uart_puts_p (const char * PROGMEM s)
{
  char c;
  while ( (c = pgm_read_byte(s)) )
    {
      uart_putc(c);
      s++;
    }
}

uint8_t uart_tx_buffer_bytes()
{
  if (uart_tx_buffer.writepos < uart_tx_buffer.readpos)
    return (uart_tx_buffer.readpos - uart_tx_buffer.writepos);
  else 
    return (uart_tx_buffer.writepos - uart_tx_buffer.readpos);
}

uint8_t uart_rx_buffer_bytes()
{
  if (uart_rx_buffer.writepos < uart_rx_buffer.readpos)
    return (uart_rx_buffer.readpos - uart_rx_buffer.writepos);
  else 
    return (uart_rx_buffer.writepos - uart_rx_buffer.readpos);
}

uint8_t uart_tx_char_present()
{
  return (uart_tx_buffer.writepos != uart_tx_buffer.readpos);
}

uint8_t uart_rx_char_present()
{
  return (uart_rx_buffer.writepos != uart_rx_buffer.readpos);
}

char uart_getc()
{
  uint8_t tmp = uart_rx_buffer.readpos;

  while (uart_rx_buffer.writepos == tmp)
    { }

  uint8_t sreg_save = SREG;
  cli();
  
  char res = uart_rx_buffer.buffer[tmp];  
  tmp++;
  tmp &= (UART_BUFSIZE-1);
  uart_rx_buffer.readpos = tmp;
  SREG = sreg_save;

  return res;
}

ISR(USART_UDRE_vect)
{
  uint8_t tmp = uart_tx_buffer.readpos;
  if (uart_tx_buffer.writepos != tmp)
    // data in buffer
    {
      UDR0 = uart_tx_buffer.buffer[tmp];
      tmp++;
      tmp &= (UART_BUFSIZE-1);
      uart_tx_buffer.readpos = tmp;
    }
  else
    // no data, so disable interrupt
    {
      UCSR0B &= ~(1 << UDRIE0);
    }
}

ISR(USART_RX_vect) 
{
  uint8_t tmp = uart_rx_buffer.writepos;
  uart_rx_buffer.buffer[tmp] = UDR0;
  tmp++;
  tmp &= (UART_BUFSIZE - 1);  
  uart_rx_buffer.writepos = tmp;
}
