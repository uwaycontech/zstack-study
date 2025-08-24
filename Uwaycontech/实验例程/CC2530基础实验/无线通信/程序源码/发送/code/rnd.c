#include "headfile.h"
/*
void rnd_init(uint16_t seed)
{
    RNDH = seed >>8;                //将种子值的高8位写入RNDH
    RNDL = seed;                    //将种子值写入RNDL
}
*/
void rnd_init(void)
{
    RFRND = 0x04;                   //无线电上电
    while(RFRND & 0x10);            //等待上电完毕
    RFST = 0xE2;                    //让无线电处于无限TX状态
    ADCCON1 &= ~0x0C;               //正常运行发生器
    RNDH = ADCTEST2;
    ADCCON1 |= 0x04;                //使能随机发生器
}

uint16_t getrandomnum(void)
{
    ADCCON1 |= 0x04;                //0000 0100 使能随机发生器
    uint16_t rand;
    rand = RNDH;                    //将RNDH的数据写入rand的高8位
    rand <<= 8;
    rand |= RNDL;                   //将RNDL的数据写入rand的低8位
    return rand;
}