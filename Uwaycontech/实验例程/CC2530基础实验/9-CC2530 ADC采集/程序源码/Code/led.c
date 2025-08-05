#include "headfile.h"
//对LED的三个引脚进行初始化
void led_init(void)
{
    P1SEL &= ~0x07;
    P1DIR |= 0x07;
    P1 = 0x00;
}
//LED的亮灭模块，参数一为LED的位数，参数二为LED 的状态
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
