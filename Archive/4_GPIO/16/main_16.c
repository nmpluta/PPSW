// 4.16
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000
#define BUTTON0_bm 0x00000010

void Delay(unsigned uiMiliSecs)
{
	unsigned long ulCounter;
	for (ulCounter=0; ulCounter<(5455*uiMiliSecs); ulCounter++)
	{
		;
	}
}

void LedInit(void)
{
	IO1DIR=LED0_bm|LED1_bm|LED2_bm|LED3_bm;
}

void LedOn(unsigned char ucLedIndeks)
{
	IO1CLR=LED0_bm|LED1_bm|LED2_bm|LED3_bm;
	
	switch (ucLedIndeks)
	{		
		case '0':
			IO1SET=LED0_bm;
			break;
		
		case '1':
			IO1SET=LED1_bm;
			break;
		
		case '2':
			IO1SET=LED2_bm;
			break;

		case '3':
			IO1SET=LED3_bm;
			break;
	}
}

int ReadButton1()
{
	if ((IO0PIN&BUTTON0_bm) == 0)
		return 1;
	else 
		return 0; 
}

int main()
{
	LedInit();
	IO0DIR=IO0DIR&(~BUTTON0_bm);
	while(1)
	{
		if (ReadButton1() == 1)
			LedOn('1');
		
		else 
			LedOn('0');
	}
}