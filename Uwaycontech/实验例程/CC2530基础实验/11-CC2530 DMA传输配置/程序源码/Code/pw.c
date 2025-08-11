#include "headfile.h"

void sys_powermode(uint8_t mode)
{
    if(mode<4)              //0-主动/空闲模式 1-PW1 2-PW2 3-PW3
    {
        PCON = 0x01;        //0000 0001 进入供电模式控制
        SLEEPCMD |= mode;   //进入对应的供电模式
    }
    else PCON = 0x00;       //唤醒设备
}