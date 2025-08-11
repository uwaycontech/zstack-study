#include "headfile.h"

void delayus(uint16_t xus)          //us级别延时
{
    for(;xus>0;xus--);
}

void delayms(uint16_t xms)          //ms级别延时
{
    for(;xms>0;xms--)
        for(uint16_t j=587;j>0;j--);
}
//    while(xus--)
//    {
//        asm("NOP");
//        asm("NOP");
//        asm("NOP");
//    }
