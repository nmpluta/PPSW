// 10.2
#include "uart.h"
#include "led.h"

int main ()
{	
	extern char cOdebranyZnak;
	UART_InitWithInt(9600);
	LedInit();
	
	while(1)
	{
		switch(cOdebranyZnak)
		{
			case '1':
				LedOn(0);
				break;
			
			case '2':
				LedOn(1);
				break;
			
			case '3':
				LedOn(2);
				break;
			
			case '4':
				LedOn(3);
				break;
			
			case 'c':
				LedOn(5);
				break;
			
			default:
				break;
		}
	}
}
