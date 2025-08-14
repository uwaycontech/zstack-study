#include "iocc2530.h"                     //Í·ÎÄ¼þ
#include "headfile.h"

uint8_t buf[32] = "Hello World!\n";
uint16_t addr = 0x0f00;
uint8_t text[32];

void main(void)
{
    clk32m_init();
    uart0_init();
    flash_write(buf,addr,sizeof(buf));
    delayms(1000);
    flash_read(text,addr,32);
    uartsendstring(text,32);
    while(1);
}

