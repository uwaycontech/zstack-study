#include<iocc2530.h>                     //头文件
#include<Headfile.h>
void delayms(uint32_t xms)          //ms级别延时
{
    for(;xms>0;xms--)
        for(uint16_t j=587;j>0;j--);
}

void main(void)
{
    led_init();
    key_init();
    while(1)
    {
        if(KEY1 == 0)
        {
            delayms(10);
            while(KEY1 == 0);
            delayms(10);
            led_proc(1,1);
            led_proc(2,1);
            led_proc(3,1);
        }
        else if(KEY2 == 0)
        {
            delayms(10);
            while(KEY2 == 0);
            delayms(10);
            led_proc(1,0);
            led_proc(2,0);
            led_proc(3,0);
        }
    }
}






