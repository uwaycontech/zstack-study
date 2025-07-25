#include<iocc2530.h>                     //ͷ�ļ�
#include<Headfile.h>

void delayms(uint16_t xms)          //ms������ʱ
{
    for(;xms>0;xms--)
        for(uint16_t j=587;j>0;j--);
}

void main(void)
{
    led_init();
    key_init();
    while(1);
}
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
