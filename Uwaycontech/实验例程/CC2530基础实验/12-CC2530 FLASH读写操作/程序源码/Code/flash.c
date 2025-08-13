#include "headfile.h"

void flash_erase(uint16_t addr)
{
    uint16_t page = addr/0x200;
    EA = 0;                 //关闭中断
    while(FCTL & 0x80);     //等待闪存控制器准备好
    FADDRH = (uint8_t)(page << 1);     //选择闪存页面
    FCTL |= 0x01;           //启动页面擦除
    while(FCTL & 0x80);     //等待闪存写完成
    EA = 1;                 //使能中断
}

void flash_write(uint8_t *data,uint16_t addr,uint8_t length)
{
    flash_erase(addr);
    FADDRH = (uint8_t)((uint16_t)addr >>10);
    FADDRL = (uint8_t)((uint16_t)addr >>2);
    DMA_DESC dmaconfig0;
    dmaconfig0.SRCADDRH = (uint8_t)((uint16_t)data >>8);
    dmaconfig0.SRCADDRL = (uint8_t)((uint16_t)data & 0xFF);
    dmaconfig0.DESTADDRH = (uint8_t)((uint16_t)&FWDATA >>8);
    dmaconfig0.DESTADDRL = (uint8_t)((uint16_t)&FWDATA & 0xFF);
    dmaconfig0.VLEN = 0;
    dmaconfig0.LENH = (uint8_t)((uint16_t)length >>8);
    dmaconfig0.LENL = (uint8_t)((uint16_t)length);
    dmaconfig0.WORDSIZE = 0;
    dmaconfig0.TMODE = 0;
    dmaconfig0.TRIG = 18;
    dmaconfig0.SRCINC = 1;
    dmaconfig0.DESTINC = 0;
    dmaconfig0.IRQMASK = 0;
    dmaconfig0.M8 = 0;
    dmaconfig0.PRIORITY = 2;
    
    //while(FCTL & 0x80);
    DMA0CFGH = (uint8_t)((uint16_t)&dmaconfig0 >>8);             //将配置结构体的首地址赋予相关SFR
    DMA0CFGL = (uint8_t)((uint16_t)&dmaconfig0 & 0xFF);
    
    DMAARM = 0x01;
    DMAIRQ = 0x00;
    DMAREQ = 0x01;
    FCTL |= 0x02;
    while((DMAIRQ & 0x01) == 0);
    DMAIRQ = 0x00;
    while(FCTL & 0x80);
}

void flash_read(uint8_t *data,uint16_t addr,uint8_t length)
{
    uint8_t memctr = MEMCTR;
    MEMCTR = (MEMCTR & 0xF8) | 0;
    for (uint8_t i = 0; i < length; i++)
    {
        // 设置要读取的地址
        FADDRH = (uint8_t)((addr + i) >> 8);
        FADDRL = (uint8_t)(addr + i);
        // 读取Flash数据（FWDATA为Flash数据寄存器）
        data[i] = FWDATA;
    }
    //uartsendstring((uint8_t*)addr,sizeof(buf));
    uartsendstring(data,length);
    MEMCTR = memctr;
}