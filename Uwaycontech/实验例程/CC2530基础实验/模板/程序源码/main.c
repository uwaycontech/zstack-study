#include<iocc2530.h>

void main(void)
{
    P1SEL &= ~0x07;
    P1DIR |= 0x07;
    P1 = 0x07;
}