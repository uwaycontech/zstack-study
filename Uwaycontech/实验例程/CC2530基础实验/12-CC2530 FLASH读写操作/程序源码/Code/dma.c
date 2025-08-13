#include "headfile.h"

uint8_t srcbuf[] = "Hello World!\n";                                //源数组
uint8_t destbuf[sizeof(srcbuf)];                                   //目标数组

void dma_init(void)
{
    DMA_DESC dmaconfig;
    dmaconfig.SRCADDRH = (uint8_t)((uint16_t)&srcbuf >>8);      //配置源地址
    dmaconfig.SRCADDRL = (uint8_t)((uint16_t)&srcbuf & 0xFF);   //&0xFF的作用是防止警告
    dmaconfig.DESTADDRH = (uint8_t)((uint16_t)&destbuf >>8);    //配置目标地址
    dmaconfig.DESTADDRL = (uint8_t)((uint16_t)&destbuf & 0xFF);
    dmaconfig.VLEN = 0x00;                                      //LEN为传送长度
    dmaconfig.LENH = (uint8_t)((uint16_t)sizeof(srcbuf) >>8);   //配置传输长度
    dmaconfig.LENL = (uint8_t)((uint16_t)sizeof(srcbuf));
    dmaconfig.WORDSIZE = 0x00;                                  //字节传送
    dmaconfig.TMODE = 0x01;                                     //块传送模式
    dmaconfig.TRIG = 0;                                         //手动触发
    dmaconfig.SRCINC = 0x01;                                    //源地址增量为1
    dmaconfig.DESTINC = 0x01;                                   //目标地址增量为1
    dmaconfig.IRQMASK = 0;                                      //中断屏蔽
    dmaconfig.M8 = 0x00;                                        //8为字节传送数据
    dmaconfig.PRIORITY = 0x02;                                  //高优先级
    DMA0CFGH = (uint8_t)((uint16_t)&dmaconfig >>8);             //将配置结构体的首地址赋予相关SFR
    DMA0CFGL = (uint8_t)((uint16_t)&dmaconfig & 0xFF);
    DMAARM = 0x01;
    DMAIRQ = 0x00;
    DMAREQ = 0x01;
    while((DMAIRQ & 0x01) == 0);
}