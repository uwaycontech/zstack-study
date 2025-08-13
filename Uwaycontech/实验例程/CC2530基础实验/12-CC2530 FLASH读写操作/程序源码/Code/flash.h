#ifndef __FLASH_H__
#define __FLASH_H__

#include "headfile.h"

void flash_erase(uint16_t addr);
void flash_write(uint8_t *data,uint16_t addr,uint8_t length);
void flash_read(uint8_t *data,uint16_t addr,uint8_t length);

extern uint8_t buf[32];

#endif