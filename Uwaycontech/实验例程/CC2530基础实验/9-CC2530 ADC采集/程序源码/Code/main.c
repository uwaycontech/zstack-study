#include "iocc2530.h"                     //头文件
#include "headfile.h"

float temp;
char buf[20];

void main(void)
{
    led_init();
    clk32m_init();
    uart0_init();
    sensor_init();
    while(1)
    {
        float sum = 0;
        for(uint8_t i=0;i<64;i++)
        {
            sum += gettemperature();    //获取温度总和
        }   
        temp = sum/64;                  //取平均温度值
        memset(buf,0,sizeof(buf));      //将buf内写入长度为buf长度的0
        sprintf(buf,"%.02f\n",temp);    //将temp内容写入buf
        uartsendstring(buf,sizeof(buf));//发送字符串
        delayms(1000);
    }
}

#pragma vector = URX0_VECTOR
__interrupt void uart0_rx(void)
{
    URX0IF = 0;                 //清除串口0接收标志位
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
