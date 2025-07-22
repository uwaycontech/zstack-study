#include "Headfile.h"
//对三个按键进行初始化
void key_init(void)
{
    P0SEL &= ~0x13;
    P0DIR |= ~0x13;
    P0INP |= ~0x13;
    P2INP |= ~0x20;
}


