// 4.4
#include <LPC21xx.H>

void delay(void)
{
	int iCounter;
	for (iCounter=0; iCounter<1000; iCounter++)
	{
		// for tylko iteruje 
	}
}

int main()
{
	IO1DIR=0x00010000;
	while(1)
	{
		IO1SET=0x00010000;
		delay();
		IO1CLR=0x00010000;
	}
}