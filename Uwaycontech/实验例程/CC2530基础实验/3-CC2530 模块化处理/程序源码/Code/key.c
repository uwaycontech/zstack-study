#include "Headfile.h"
//�������������г�ʼ��
void key_init(void)
{
    P0SEL &= ~0x13;
    P0DIR |= ~0x13;
    P0INP |= ~0x13;
    P2INP |= ~0x20;
}


