#include "iocc2530.h"                     //头文件
#include "headfile.h"

char buf[20];
void main(void)
{
    clk32m_init();
    uart0_init();
    dma_init();
    DMAARM = 0x01;                              //启动DMA通道0
    DMAIRQ = 0x00;                              //清除所有中断标志位
    DMAREQ = 0x01;                              //DMA通道0传送请求
    while((DMAIRQ & 0x01) == 0);                //等待DMA通道0传送完成
    sprintf(buf,"finish\r\n");
    uartsendstring(buf,sizeof(buf));            //传送完成串口输出
    uartsendstring(destbuf,sizeof(destbuf));    //检测是否传输完成
    while(1);
}

