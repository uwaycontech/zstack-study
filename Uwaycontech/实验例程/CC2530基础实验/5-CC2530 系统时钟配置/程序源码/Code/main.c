#include "iocc2530.h"                     //ͷ�ļ�
#include "headfile.h"

void main(void)
{
    led_init();
    clk32m_init();
    while(1)
    {
        led_proc(1,1);
        delayms(500);
        led_proc(1,0);
        delayms(500);
    }
}
/*
uint8_t status=0;
#pragma vector = P0INT_VECTOR
__interrupt void interrupt(void)
{
    if(P0IFG & 0x01)			//�ж��Ƿ�����ж�
    {
        delayms(10);			//��������
        while(KEY1 == 0);
        delayms(10);			//�ͷ�����
        status = ~status;	    //�ı�״̬
        led_proc(1,status);
    }
    //�����ж�״̬��־λ
    P0IFG = 0;
    P0IF = 0;
}
*/
