#include "iocc2530.h"                     //头文件
#include "headfile.h"

void main(void)
{
    led_init();
    clk32m_init();
    uart0_init();
    while(1)
    {
    }
}

#pragma vector = URX0_VECTOR
__interrupt void uart0_rx(void)
{
    char buf;
    URX0IF = 0;                 //清除串口0接收标志位
    buf = U0DBUF;               //从串口0接收器读取数据
    LED1 = !LED1;
    U0DBUF = buf;               //将ch放进串口0发送器内
    while(UTX0IF == 0);         //等待串口0发送完毕
    UTX0IF = 0;                 //清除串口0发送标志位
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
