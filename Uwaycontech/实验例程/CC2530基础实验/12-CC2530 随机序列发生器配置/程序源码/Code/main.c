#include "iocc2530.h"
#include "headfile.h"

char buf[20];
uint16_t rand;
void main(void)
{
    clk32m_init();
    uart0_init();
    rnd_init();
    key_init();
    led_init();
//    rnd_init(0x2000);                       //给定种子值为0x2000
    //注意种子值不可为0x0000和0x8003
    while(1)
    {
        switch((rand%10)%3)                         //对随机数的个位数进行3取余
        {
        case 0:led_proc(1,1);led_proc(2,0);led_proc(3,0);break;
        case 1:led_proc(1,0);led_proc(2,1);led_proc(3,0);break;
        case 2:led_proc(1,0);led_proc(2,0);led_proc(3,1);break;
        default:break;
        }
    }
}

#pragma vector = P0INT_VECTOR
__interrupt void P0_int(void)
{
    if(P0IFG & 0x01)
    {
        uint8_t state=0;
        delayms(10);
        rand = getrandomnum();                      //获取随机数
        state++;
        while(KEY1 == 0);
        delayms(10);
        if(state)
        {
            buf[2] = (rand)%10 + '0';               //获取个位数
            buf[1] = (rand/10)%10 + '0';            //获取十位数
            buf[0] = (rand/100)%10 + '0';           //获取百位数
            //将整数转换为对应的字符型，只需加上'0'
            uartsendstring(buf,3);
            uartsendstring("\r\n",2);
        }
    }
    P0IFG = 0;
    P0IF = 0;
}