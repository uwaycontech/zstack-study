#include<iocc2530.h>					//ͷ�ļ�
void delay_ms(unsigned int xms)			//ms������ʱ
{
    for(;xms>0;xms--)
      for(unsigned int j=587;j>0;j--);
}
void main(void)
{
    P1SEL &= ~0x07;						//����P1_2-P1_0Ϊͨ��IO��
    P1DIR |= 0x07;						//����P1_2-P1_0Ϊ���ģʽ
    P1 = 0x00;							//����P1_2-P1_0Ϊ�͵�ƽ
    P0SEL &= ~0x01;						//����P0_0Ϊͨ��IO��
    P0DIR |= 0x00;						//����P0_0Ϊ����ģʽ
    P0INP |= 0x00;						//����P0_0Ϊ�ϡ���������ģʽ
    while(1)
    {
        if(P0_0 == 0)					//��⵽����1���Ƿ���
        {
            delay_ms(10);				//��������ʱ����һ��5-20ms����ʱ
            while(P0_0 == 0);			//������δ���ͷ�ʱ������ѭ��	
            delay_ms(10);				//�����ͷ�ʱ����һ��5-20ms����ʱ
            P1 = ~P1;					//��P1��IO�ڵĵ�ƽ��ת
        }
    }
}
