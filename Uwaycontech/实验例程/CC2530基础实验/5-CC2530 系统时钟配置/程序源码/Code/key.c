#include "headfile.h"
//�������������г�ʼ��
void key_init(void)
{
    P0SEL &= ~0x13;
    P0DIR |= ~0x13;
    P0INP |= ~0x13;
    P2INP |= ~0x20;
    //�жϳ�ʼ��
    EA = 1;			//�������ж�
    P0IE = 1;		//����P0���ж�
    P0IEN |= 0x01;	//����P0_0�ж�
    PICTL |= 0x01;	//����P0_0-P0_7Ϊ�½��ش���
}


