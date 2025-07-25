#include "headfile.h"
//对三个按键进行初始化
void key_init(void)
{
    P0SEL &= ~0x13;
    P0DIR |= ~0x13;
    P0INP |= ~0x13;
    P2INP |= ~0x20;
    //中断初始化
    EA = 1;			//开启总中断
    P0IE = 1;		//开启P0组中断
    P0IEN |= 0x01;	//开启P0_0中断
    PICTL |= 0x01;	//配置P0_0-P0_7为下降沿触发
}


