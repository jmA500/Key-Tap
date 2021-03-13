#ifndef MENU_H
#define MENU_H

#include <stdint.h>
#include <avr/pgmspace.h>

typedef struct
{
  void* next;
  void* prev;
  char* name;
  uint8_t porta_mask;
  uint8_t porta_setting;
} menu_item_t;

typedef struct 
{
  void* next;
  void* prev;
  char * name;
  menu_item_t* first_item;
} menu_sub_entry_t;

typedef struct 
{
  void* next;
  void* prev;
  char* name;
  menu_sub_entry_t* first_sub;
} menu_entry_t;

void menu_exec();

extern menu_entry_t trapdoor;

extern menu_sub_entry_t td_chip;
extern menu_item_t td_chip_0k;
extern menu_item_t td_chip_512k;

extern menu_sub_entry_t td_ranger;
extern menu_item_t td_ranger_0k;
extern menu_item_t td_ranger_512k;
extern menu_item_t td_ranger_1024k;
extern menu_item_t td_ranger_1536k;
extern menu_item_t td_ranger_max;

extern menu_entry_t kickflash;
extern menu_sub_entry_t kf_version;
extern menu_item_t kf_version_13;
extern menu_item_t kf_version_20;
extern menu_item_t kf_version_12;

#endif
