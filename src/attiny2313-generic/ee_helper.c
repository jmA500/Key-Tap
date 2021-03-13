#include "ee_helper.h"
#include <avr/eeprom.h>

uint8_t EEMEM conf[] = { CONFIG_DEFAULT };

uint8_t ee_load_config()
{
  return eeprom_read_byte(conf);
}

void ee_save_config(uint8_t c)
{
  uint8_t res = eeprom_read_byte(conf);
  if (res != c)
    {
      eeprom_write_byte(conf,c);
    }
}
