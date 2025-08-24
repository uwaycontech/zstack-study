#include "iocc2530.h"
#include "headfile.h"

void main(void)
{
    clk32m_init();
//	key_init();
    led_init();
	rf_init();
	SHORT_ADDR0 = 0xEF;			//…Ë÷√Õ¯¬Áµÿ÷∑Œ™0xBEEF
	SHORT_ADDR1 = 0xBE;
    while(1);
}
/*
#pragma vector = P0INT_VECTOR
__interrupt void P0_int(void)
{
    if(P0IFG & 0x01)
    {
	  	delayms(20);
		while(KEY1 == 0);
		delayms(20);
		LED1 = !LED1;
	  	rf_send(sendpacket,11);
    }
    P0IFG = 0;
    P0IF = 0;
}
*/