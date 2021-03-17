// 12.3
#include "uart.h"
#include "keyboard.h"
#include "servo.h"
#include "myString.h"
#include "command_decoder.h"
#include "timer.h"
#include <LPC21xx.H>


unsigned char ucTest[] = "test123";

int main ()
{	
	UART_InitWithInt(9600);
	InitTimer0();
	
	while(1)
	{
		if (eTransmiter_GetStatus() == FREE)
			Transmiter_SendString("test123");
		
		else 
			U0THR = Transmiter_GetCharacterFromBuffer();
	
		WaitOnTimer0(10000);
	}
}
