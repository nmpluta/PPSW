// 4.6
#include <LPC21xx.H>

void delay(unsigned iMiliSecs)
{
	unsigned long ulCounter;
	for (ulCounter=0; ulCounter<(5455*iMiliSecs); ulCounter++)
	{
		;// for tylko iteruje (opoznienie)
	}
}

int main()
{
	IO1DIR=0x00010000;
	while(1)
	{
		delay(1);
		IO1SET=0x00010000;
		delay(1000);
		IO1CLR=0x00010000;
	}
}
