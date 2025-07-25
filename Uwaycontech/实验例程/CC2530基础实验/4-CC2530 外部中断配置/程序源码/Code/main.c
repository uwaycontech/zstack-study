#include<iocc2530.h>                     //头文件
#include<Headfile.h>

void delayms(uint16_t xms)          //ms级别延时
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
