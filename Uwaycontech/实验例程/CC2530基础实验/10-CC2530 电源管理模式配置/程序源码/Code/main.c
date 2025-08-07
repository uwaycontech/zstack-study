#include "iocc2530.h"                     //头文件
#include "headfile.h"


void main(void)
{
    uint8_t i;
    led_init();
    key_init();
    while(1)
    {
        LED2 = !LED2;
        LED1 = 1;
        delayms(500);
        if(++i == 20)               //当LED2闪烁10次进入睡眠
        {
            i = 0;
            LED1 = 0;
            sys_powermode(3);       //进入PW3模式
        }
    }
}

#pragma vector = P0INT_VECTOR
__interrupt void p0interrupt(void)
{
    if(P0IFG & 0x01)			//判断是否进入中断
    {
        delayms(10);			//按下消抖
        while(KEY1 == 0);
        delayms(10);			//释放消抖
    }
    sys_powermode(4);           //唤醒设备返回主动模式
    //消除中断状态标志位
    P0IFG = 0;
    P0IF = 0;
}

