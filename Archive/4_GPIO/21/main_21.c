// 4.21
#include <LPC21xx.H>
#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000
#define BUTTON0_bm 0x00000010
#define BUTTON1_bm 0x00000040
#define BUTTON2_bm 0x00000020
#define BUTTON3_bm 0x00000080

enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

unsigned uiStepCounter = 0; 

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

void KeyboardInit(void)
{
	IO0DIR=IO0DIR&(~(BUTTON0_bm|BUTTON1_bm|BUTTON2_bm|BUTTON3_bm));
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

enum KeyboardState eKeyboardRead()
{
	if ((IO0PIN&BUTTON0_bm) == 0)
		return BUTTON_0;
	
	else if ((IO0PIN&BUTTON1_bm) == 0)
		return BUTTON_1;
	
	else if ((IO0PIN&BUTTON2_bm) == 0)
		return BUTTON_2;
	
	else if ((IO0PIN&BUTTON3_bm) == 0)
		return BUTTON_3;
	
	else 
		return RELASED;
}

void StepLeft(void)
{
	uiStepCounter=(uiStepCounter+1)%4;
	LedOn('0'+uiStepCounter);
}

void StepRight(void)
{
	uiStepCounter=(uiStepCounter-1)%4;
	LedOn('0'+uiStepCounter);
}

int main()
{
	LedInit();
	KeyboardInit();
	while(1)
	{
		StepRight();
		Delay(250);
	}
}