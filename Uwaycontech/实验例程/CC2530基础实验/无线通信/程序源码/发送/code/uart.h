#ifndef __UART_H__
#define __UART_H__

#include "headfile.h"

void uart0_init(void);
void uartsendstring(char *data,uint8_t len);

#endif