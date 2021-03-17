// 10.3 detector
#include "uart.h"
#include "keyboard.h"
#include "servo.h"

#define NULL '\0'

int main ()
{	
	extern char cOdebranyZnak;
	UART_InitWithInt(9600);
	ServoInit(8);
	KeyboardInit();
	
	while(1)
	{
		switch(cOdebranyZnak)
		{
			case '1':
				ServoGoTo(50);
				break;
			
			case '2':
				ServoGoTo(100);
				break;
			
			case '3':
				ServoGoTo(150);
				break;
			
			case 'c':
				ServoCallib();
				break;
			
			default:
				break;
		}
		cOdebranyZnak = NULL;
		
		switch(eKeyboardRead())
		{
			case BUTTON_0:
				ServoCallib();
				break;	
			
			case BUTTON_1:
				ServoGoTo(50);
				break;
			
			case BUTTON_2:
				ServoGoTo(100);
				break;
			
			case BUTTON_3:
				ServoGoTo(150);
				break;
			
			default:
				break;
		}
	}
}
