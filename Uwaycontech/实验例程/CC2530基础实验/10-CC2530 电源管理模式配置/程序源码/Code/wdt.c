#include "headfile.h"

void wdt_init(void)
{
    WDCTL |= 0x08;      //0000 1000 看门狗模式 定时器间隔值为1s
}

void wdtfeet(void)      //喂狗操作
{
    WDCTL = 0xA0;
    WDCTL = 0x50;
}