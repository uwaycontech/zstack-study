#ifndef __RF_H__
#define __RF_H__

#include "headfile.h"

void rf_init(void);
void rf_send(uint8_t *buf,uint8_t len);
void rf_receive(void);

extern uint8_t sendpacket[13];

#endif