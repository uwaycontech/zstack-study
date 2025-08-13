#include "iocc2530.h"                     //м╥нд╪Ч
#include "headfile.h"

uint8_t buf[32] = "Hello World!\n";
uint16_t addr = 0x1000;
uint8_t text[32];

void main(void)
{
    clk32m_init();
    uart0_init();
    flash_write(buf,addr,sizeof(buf));
    flash_read(text,addr,sizeof(text));
    while(1);
}

