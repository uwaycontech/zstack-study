#ifndef __UART_H__
#define __UART_H__

#include "headfile.h"

void uart0_init(void);
void uartsendstring(uint8_t *data,uint8_t len);

#endif