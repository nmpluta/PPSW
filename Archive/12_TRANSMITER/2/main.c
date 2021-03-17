// 12.2
#include "uart.h"
#include "keyboard.h"
#include "servo.h"
#include "myString.h"
#include "command_decoder.h"
#include "timer.h"

unsigned char ucTest[] = "test123";

int main ()
{	

	UART_InitWithInt(9600);
	Transmiter_SendString(ucTest);
	
	while(1)
	{
	}
}
