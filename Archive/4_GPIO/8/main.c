// 4.8
#include <LPC21xx.H>

void delay(unsigned uMiliSecs)
{
	unsigned long ulCounter;
	for (ulCounter=0; ulCounter<(5455*uMiliSecs); ulCounter++)
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
		delay(50);	// 50ms - 1/2 T 
		IO1CLR=0x00010000;
		delay(50);	// 50ms - 1/2 T 
	}
}