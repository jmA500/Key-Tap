#include "ee_helper.h"
#include <avr/eeprom.h>

/*
 * This array stores the config information. To provide some wear
 * leveling for the EEPROM cells, this code provides two arrays. The
 * arrays are written in increasing order. The last free index i is
 * the first one in the array such that conf_tag[i] equal to
 * EE_MEM_TAG_INVALID. The entry conf_data[i-1] contains the most
 * recently written data. */

#define UART_DEBUG 1
#include "uart_helper.h"

/* Note  that we use the erase before write functionality here,
 * which actually does more erasing that necessary. */

uint8_t EEMEM conf_initialized[] = {EE_MEM_TAG_INVALID, EE_MEM_TAG_INVALID}; 
uint8_t EEMEM conf_data[CONF_SIZE];
uint8_t EEMEM conf_tag[CONF_SIZE];

void ee_initialize()
{
  uart_dbg("EE ini\n");
  eeprom_write_byte(conf_tag,EE_MEM_TAG_INVALID);
  eeprom_write_byte(conf_initialized,EE_MEM_TAG_VALID);
  eeprom_write_byte(conf_initialized+1,EE_MEM_TAG_VALID);
}

uint8_t ee_is_initialized()
{
  uart_dbg("EE is_in");
  uint8_t data = eeprom_read_byte(conf_initialized+1);
  uint8_t res = 0;
  
  if (data==EE_MEM_TAG_VALID)
    {
      res =1;
    }
  uart_dbg_hexnl(res);
  return res;
}

uint8_t ee_first_free_index()
{
  uint8_t i = 0;
  if (ee_is_initialized())
    {
      while ((eeprom_read_byte(conf_tag + i) != EE_MEM_TAG_INVALID)
	     && (++i < CONF_SIZE))
	{ }
    }
  else
    {
      ee_initialize();
    }
  uart_dbg("EE fr ");
  uart_dbg_hexnl(i);
  return i;
}

uint8_t ee_load_config()
{
  uart_dbg("EE ld ");
  
  uint8_t i = ee_first_free_index();
  uint8_t res = CONFIG_DEFAULT;
  if (i > 0)
    {
      res = eeprom_read_byte(conf_data + i - 1);
    }
  uart_dbg_hexnl(res);
  return res;
}

void ee_save_config(uint8_t c)
{
  uart_dbg("EE sv ");
  uart_dbg_hexnl(c);
  
  uint8_t i = ee_first_free_index();

  if (i > 0)
    {
      uint8_t data = eeprom_read_byte(conf_data + i - 1);
      if (data == c)
	{
	  uart_dbg("EE sv skip\n");
	  return;
	}
    }
  
  if (i == (CONF_SIZE-1))
    {
      i = 0;
    }
  
  eeprom_write_byte(conf_tag + i, EE_MEM_TAG_VALID);
  eeprom_write_byte(conf_tag + i + 1, EE_MEM_TAG_INVALID);
  eeprom_write_byte(conf_data + i, c);
}

void dump_eeprom()
{
#if UART_DEBUG > 0
  uart_dbg("EEPROM: Tag Data\n");
  for (uint8_t i=0; i<CONF_SIZE; ++i)
    {
      uart_dbg("        ");
      uart_dbg_hex(eeprom_read_byte(conf_tag+i));
      uart_dbg_hexnl(eeprom_read_byte(conf_data+i));
      uart_wait_free();
    }
#endif
}
