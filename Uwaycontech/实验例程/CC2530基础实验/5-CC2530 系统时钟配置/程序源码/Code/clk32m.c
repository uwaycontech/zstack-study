#include "headfile.h"

void clk32m_init(void)
{
    SLEEPCMD &= 0xFB;               //1111 1011 ������Ƶʱ��Դͬʱ����
    while((SLEEPSTA & 0x40) == 0);  //0100 0000 �ж�32M�����Ƿ������ȶ�
    delayus(63);
    CLKCONCMD &= 0xF8;              //1111 1000 ���ò���Ƶ
    CLKCONCMD &= 0xBF;              //1011 1111 ����32Mʱ��ԴΪ��ʱ��Դ
    while(CLKCONSTA & 0x40);        //0100 0000 �ж�32Mʱ��Դ�Ƿ�Ϊ��ʱ��Դ
}
