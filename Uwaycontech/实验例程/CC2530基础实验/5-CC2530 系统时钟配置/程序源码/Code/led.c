#include "headfile.h"
//��LED���������Ž��г�ʼ��
void led_init(void)
{
    P1SEL &= ~0x07;
    P1DIR |= 0x07;
    P1 = 0x00;
}
//LED������ģ�飬����һΪLED��λ����������ΪLED ��״̬
void led_proc(uint8_t led,uint8_t light)
{
    switch(led)
    {
        case 1:LED1 = light;break;
        case 2:LED2 = light;break;
        case 3:LED3 = light;break;
        default :break;
    }
}
