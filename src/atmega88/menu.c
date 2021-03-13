#include "menu.h"
#include "pinconfig.h"
#include "lcd.h"

#include <stdlib.h>

menu_entry_t trapdoor =  {
  .next = (void*) &kickflash,
  .prev = (void*) &kickflash,
  .name = "Trapdoor RAM",
  .first_sub = &td_chip,
};

menu_sub_entry_t td_chip =
  {
    .next = (void*) &td_ranger,
    .prev = 0,
    .name = "ChipRAM",
    .first_item = &td_chip_0k,
  };
  
menu_item_t td_chip_0k =
  {
    .next = (void*) &td_chip_512k,
    .prev = NULL,
    .name = "  0k",
    .porta_mask = (1<<CHIPRAM),
    .porta_setting = 0,
  };

menu_item_t td_chip_512k =
  {
    .name = "512k",
    .next = NULL,
    .prev = (void*) &td_chip_0k,
    .porta_mask = (1<<CHIPRAM),
    .porta_setting = (1<<CHIPRAM),
  };
  
menu_sub_entry_t td_ranger =
  {
    .next = NULL,
    .prev = (void*) &td_chip,
    .name  = "SlowRAM",
    .first_item = &td_ranger_0k,
  };

menu_item_t td_ranger_0k =
  {
    .next = (void*) &td_ranger_512k,
    .prev = NULL,
    .name = "   0k",
    .porta_mask = (1<<EXRAM) | (1<<CONF0) | (1<<CONF1),
    .porta_setting = 0,
  };

menu_item_t td_ranger_512k =
  {
    .next = (void*) &td_ranger_1024k,
    .prev = (void*) &td_ranger_0k,
    .name = " 512k",
    .porta_mask = (1<<EXRAM) | (1<<CONF0) | (1<<CONF1),
    .porta_setting = 0,
  };

menu_item_t td_ranger_1024k =
  {
    .next = (void*) &td_ranger_1536k,
    .prev = (void*) &td_ranger_1024k,
    .name = "1024k",
    .porta_mask = (1<<EXRAM) | (1<<CONF0) | (1<<CONF1),
    .porta_setting = 0,
  };

menu_item_t td_ranger_1536k =
  {
    .next = (void*) &td_ranger_max,
    .prev = (void*) &td_ranger_1024k,
    .name = "1536k",
    .porta_mask = (1<<EXRAM) | (1<<CONF0) | (1<<CONF1),
    .porta_setting = 0,
  };

menu_item_t td_ranger_max =
  {
    .next = NULL,
    .prev = (void*) &td_ranger_1536k,
    .name = " Max.",
    .porta_mask = (1<<EXRAM) | (1<<CONF0) | (1<<CONF1),
    .porta_setting = 0,
  };

menu_entry_t kickflash =
  {
    .next = NULL,
    .prev = (void*) &trapdoor,
    .name = "Kickflash",
    .first_sub = &kf_version,
  };
  
menu_sub_entry_t kf_version = 
  {
    .next = NULL,
    .prev = NULL,
    .name = "Version",
    .first_item = &kf_version_13,
  };

menu_item_t kf_version_13 =
  {
    .next = (void*) &kf_version_20,
    .prev = NULL,
    .name = "v1.3 ",
    .porta_mask = (1<<KF0) | (1<<KF1),
    .porta_setting = 0,
  };

menu_item_t kf_version_20 =
  {
    .next = (void*) &kf_version_12,
    .prev = (void*) &kf_version_13,
    .name = "v2.04",
    .porta_mask = (1<<KF0) | (1<<KF1),
    .porta_setting = (1<<KF0),
  };

menu_item_t kf_version_12 =
  {
    .next = NULL,
    .prev = (void*) &kf_version_20,
    .name = "v1.2 ",
    .porta_mask = (1<<KF0) | (1<<KF1),
    .porta_setting = (1<<KF1),
  };

menu_entry_t* current_entry = &trapdoor;
menu_sub_entry_t* current_sub_entry = &td_chip;
menu_item_t* current_item = &td_chip_0k;
uint8_t menu_select_level;

void menu_display()
{
  lcd_clrscr();
  lcd_gotoxy(0,0);
  if (menu_select_level == 0)
    lcd_putc('#');
  else
    lcd_putc(' ');
  lcd_puts(current_entry->name);
}

void menu_exec() 
{
  menu_display();
}

