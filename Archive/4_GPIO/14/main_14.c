// 4.14
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

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
	IO1SET=LED0_bm;
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

int main()
{
	while(1)
	{
		LedInit();
		Delay(250);
		IO1CLR=LED0_bm;
		
		LedOn('1');
		Delay(250);
		
		LedOn('2');
		Delay(250);
		
		LedOn('3');
		Delay(250);
	}
}