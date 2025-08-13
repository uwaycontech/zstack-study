#include "headfile.h"

void clk32m_init(void)
{
    SLEEPCMD &= 0xFB;               //1111 1011 两个高频时钟源同时起振
    while((SLEEPSTA & 0x40) == 0);  //0100 0000 判断32M晶振是否起振稳定
    delayus(63);
    CLKCONCMD &= 0xF8;              //1111 1000 设置不分频
    CLKCONCMD &= 0xBF;              //1011 1111 设置32M时钟源为主时钟源
    while(CLKCONSTA & 0x40);        //0100 0000 判断32M时钟源是否为主时钟源
}
