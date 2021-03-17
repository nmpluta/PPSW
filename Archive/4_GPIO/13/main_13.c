// 4.13
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

void delay(unsigned uMiliSecs)
{
	unsigned long ulCounter;
	for (ulCounter=0; ulCounter<(5455*uMiliSecs); ulCounter++)
	{
		;
	}
}

void LedInit(void)
{
	IO1DIR=LED0_bm|LED1_bm|LED2_bm|LED3_bm;
	IO1SET=LED0_bm;
}

int main()
{
	while(1)
	{
		LedInit();
		delay(250);
		IO1CLR=LED0_bm;
		
		IO1SET=LED1_bm;
		delay(250);
		IO1CLR=LED1_bm;
		
		IO1SET=LED2_bm;
		delay(250);
		IO1CLR=LED2_bm;
		
		IO1SET=LED3_bm;
		delay(250);
		IO1CLR=LED3_bm;
	}
}