/************************************************************************
Title:    Helper functions to store configuration in the eeprom.

Author:   Jan Metzger <jm@metweb.de>

License:  GNU General Public License 

LICENSE:
    Copyright (C) 2014 Jan Metzger

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
************************************************************************/

#ifndef EE_HELPER_H
#define EE_HELPER_H

#include <stdint.h>

#define CONFIG_DEFAULT 0x00

void    ee_save_config(uint8_t c);
uint8_t ee_load_config();

#endif
