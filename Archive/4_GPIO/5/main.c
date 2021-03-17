// 4.5
#include <LPC21xx.H>

void delay(void)
{
	unsigned long ulCounter;
	for (ulCounter=0; ulCounter<12e5; ulCounter++)
	{
		;// for tylko iteruje (opoznienie)
	}
}

int main()
{
	IO1DIR=0x00010000;
	while(1)
	{
		IO1SET=0x00010000;
		delay()
		IO1CLR=0x00010000;
	}
}
