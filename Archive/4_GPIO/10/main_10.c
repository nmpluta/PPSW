// 4.10
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED3_bm 0x00080000

void delay(unsigned uMiliSecs)
{
	unsigned long ulCounter;
	for (ulCounter=0; ulCounter<(5455*uMiliSecs); ulCounter++)
	{
		;
	}
}

int main()
{
	IO1DIR=LED3_bm;
	while(1)
	{
		IO1SET=LED3_bm;
		delay(50);	
		IO1CLR=LED3_bm;
		delay(50);	
	}
}