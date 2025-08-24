#include "headfile.h"

#define RF_DATA 1

uint8_t sendpacket[] = {0x0C,0x61,0x88,0x00,0x07,0x20,0xEF,0xBE,0x20,0x50,RF_DATA};
//第一位表示后面还有12个字节待发送
//第五和六位表示PANID，即个域网ID，0x2007
//第七和八位表示目标设备的网络地址，0xBEEF
//第九和十位表示本地模块的网络地址，0x2050
//第十一位表示待发送的有效数据
//后面还有第十二和十三位是硬件自动追加的校验码

void rf_init(void)						//射频模块初始化，接收端和发送端都要初始化
{
	EA = 0;
	FRMCTRL0 |= 0x60;
	TXFILTCFG = 0x09;
	AGCCTRL1 = 0x15;
	FSCAL1 = 0x00;
	
	RFIRQM0 |= 0x40;					//开启射频接收中断
	IEN2 |= 0x01;						//开启射频中断
	FREQCTRL = 11 + (25 - 11) * 5;		//设置为25号信道，其载波频率为2.475GHz
	PAN_ID0 = 0x07;						//设置PANID为0x2007
	PAN_ID1 = 0x20;	
	RFST = 0xEC;						//清空接收缓存区
	RFST = 0xE3;						//开启接收使能
	EA = 1;								//开启总中断
}
void rf_send(uint8_t *buf,uint8_t len)	//发送模块
{
	RFST = 0xEC;						//清空接收缓存区
	RFST = 0xE3;						//清除接受标志位
	while(FSMSTAT1 & 0x22);				//等待发送准备好
	RFST = 0xEE;						//清空发送缓存区
	RFIRQF1 &= ~0x02;					//清除发送标志位
	buf[10] = LED1;
	for(uint8_t i = 0;i<len;i++)	
	{	
	  RFD = buf[i];						//将待发送的数据存入发送缓存区
	}	
	RFST = 0xE9;						//将发送缓存区的数据发送出去
	while(RFIRQF1 & 0x02 == 0);			//等待发送完毕
	RFIRQF1 = ~0x02;					//清除发送标志位
}	

void rf_receive(void)					//接收模块
{
  	uint8_t len = 0;
	RFIRQM0 &= ~0x40;					//关闭射频接收中断
	IEN2 &= ~0x01;						//关闭射频中断
	EA = 1;								//开启总中断
	len = RFD;							//读取接收缓存区的第一个数据，可以得知后面还有多少个字节
	while(len)							//接收缓存区的数据未读取完
	{
		uint8_t buf = RFD;				//读取接收缓存区内的数据
		if(len == 3) LED2 = buf;		//当读取到第十一位数据即RF_DATA时，此时len为3
		len--;
	}
	EA = 0;								//关闭总中断
	RFIRQM0 |= 0x40;					//开启射频接收中断
	IEN2 |= 0x01;						//开启射频中断
}

#pragma vector = RF_VECTOR
__interrupt void rx_int(void)
{
	EA = 0;
	if(RFIRQF0 & 0x40)
	{
		rf_receive();
		RFIRQF0 &= ~0x40;				//清除中断标志
	}
	S1CON = 0;							//清空中断标志
	RFST = 0xEC;						//清空接收缓存区
	RFST = 0xE3;						//清除接收标志位
	EA = 1;								//开启总中断
}
