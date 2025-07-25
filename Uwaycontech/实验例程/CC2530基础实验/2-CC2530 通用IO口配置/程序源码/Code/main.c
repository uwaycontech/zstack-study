#include<iocc2530.h>					//头文件
void delay_ms(unsigned int xms)			//ms级别延时
{
    for(;xms>0;xms--)
      for(unsigned int j=587;j>0;j--);
}
void main(void)
{
    P1SEL &= ~0x07;						//配置P1_2-P1_0为通用IO口
    P1DIR |= 0x07;						//配置P1_2-P1_0为输出模式
    P1 = 0x00;							//配置P1_2-P1_0为低电平
    P0SEL &= ~0x01;						//配置P0_0为通用IO口
    P0DIR |= 0x00;						//配置P0_0为输入模式
    P0INP |= 0x00;						//配置P0_0为上、下拉输入模式
    while(1)
    {
        if(P0_0 == 0)					//检测到按键1被是否按下
        {
            delay_ms(10);				//按键按下时进行一次5-20ms的延时
            while(P0_0 == 0);			//当按键未被释放时进入死循环	
            delay_ms(10);				//按键释放时进行一次5-20ms的延时
            P1 = ~P1;					//让P1组IO口的电平翻转
        }
    }
}
