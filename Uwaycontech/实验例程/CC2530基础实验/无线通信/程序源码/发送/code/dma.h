#ifndef __DMA_H__
#define __DMA_H__

#include "headfile.h"

void dma_init(void);

extern char srcbuf[20];
extern char destbuf[sizeof(srcbuf)];


#pragma bitfields=reversed
typedef struct
{
    uint8_t SRCADDRH;           //源地址高8位
    uint8_t SRCADDRL;           //源地址低8位
    uint8_t DESTADDRH;          //目的地址高8位
    uint8_t DESTADDRL;          //目的地址低8位
    uint8_t VLEN        :3;     //可变长度传输模式
    uint8_t LENH        :5;     //传送长度高5位
    uint8_t LENL        :8;     //传送长度低8位
    uint8_t WORDSIZE    :1;     //8位或16位传送，字节或字传送
    uint8_t TMODE       :2;     //传送模式选择
    uint8_t TRIG        :5;     //触发事件选择
    uint8_t SRCINC      :2;     //源地址增量 -1/0/1/2
    uint8_t DESTINC     :2;     //目标地址增量 -1/0/1/2
    uint8_t IRQMASK     :1;     //中断屏蔽
    uint8_t M8          :1;     //8位传输长度
    uint8_t PRIORITY    :2;     //优先级别
}DMA_DESC;
#pragma bitfields=default

#endif