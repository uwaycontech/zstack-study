#ifndef _HEADFILE_H_
#define _HEADFILE_H_

#include "iocc2530.h"
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "clk32m.h"
#include "timer1.h"
#include "wdt.h"
#include "uart.h"
#include "adc.h"
#include "pw.h"
#include "dma.h"
#include "flash.h"

//LED
#define LED1 P1_0
#define LED2 P1_1
#define LED3 P1_2

//Key
#define KEY1 P0_0
#define KEY2 P0_1
#define KEY3 P0_4

//BEEP
#define BEEP P2_0

//PW
#define PW1 0x01
#define PW2 0x02
#define PW3 0x03
#define WAKEUP 0x04

#endif
