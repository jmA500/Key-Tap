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
