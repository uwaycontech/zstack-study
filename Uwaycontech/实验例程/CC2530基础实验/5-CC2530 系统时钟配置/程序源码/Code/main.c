#include "iocc2530.h"                     //头文件
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
    if(P0IFG & 0x01)			//判断是否进入中断
    {
        delayms(10);			//按下消抖
        while(KEY1 == 0);
        delayms(10);			//释放消抖
        status = ~status;	    //改变状态
        led_proc(1,status);
    }
    //消除中断状态标志位
    P0IFG = 0;
    P0IF = 0;
}
*/
