#include "headfile.h"

void timer1_init(void)
{
    T1CTL |= 0x0d;           //0000 1101 128分频 自动运行模式
    T1STAT |= 0x21;          //0010 0001 开启通道0中断。
}