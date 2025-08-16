#include "headfile.h"

void sensor_init(void)                      //初始化片内温度传感器
{
    clk32m_init();                          //切换为32MHz时钟源
    TR0 = 0x01;                             //连接温度传感器到SOC_ADC
    ATEST = 0x01;                           //使能温度传感器
}

float gettemperature(void)
{
    uint16_t value;
    ADCCON3 = 0x3E;                         //0011 1110 选择内部参考电压、512抽取率，通道选择温度传感器
    ADCCON1 |= 0x30;                        //0011 0000 启动模式选择手动
    ADCCON1 |= 0x40;                        //0100 0000 开始转换
    while((ADCCON1 & 0x80) == 0);           //1000 0000 等待转换结束
    value = ADCL >> 4;                      //ADCL寄存器低2位无效
    value |= (((uint16_t) ADCH) << 4);
    return (value - 1367.5) / 4.5 - 4;      //根据AD值计算出实际芯片温度
}