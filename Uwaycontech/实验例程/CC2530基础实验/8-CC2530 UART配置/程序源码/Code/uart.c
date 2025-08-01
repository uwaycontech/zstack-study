#include "headfile.h"

void uart0_init(void)
{
    PERCFG &= ~0x01;    //1111 1110 指定串口0在备用位置1，即P0_3和P0_2
    P0SEL |= 0x0C;      //0000 1100 配置P0_3和P0_2为具有片上外设功能的IO口
    U0CSR |= 0xC0;      //1100 0000 配置串口0为UART功能 使能接收器
    U0GCR = 8;          //设置BAUD_E为8
    U0BAUD = 59;        //设置BAUD_M为59 结合BAUD_E和BAUD_M设置波特率为9600
    URX0IE = 1;         //使能串口0接收
    EA = 1;             //打开CPU总中断
}