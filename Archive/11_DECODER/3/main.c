// 11.3
#include "uart.h"
#include "keyboard.h"
#include "servo.h"
#include "myString.h"
#include "command_decoder.h"

int main ()
{	
	char cReceivedString[RECIEVER_SIZE];
	unsigned int uiDesiredPosition = 0;
	UART_InitWithInt(9600);
	ServoInit(8);
	KeyboardInit();
	
	while(1)
	{
		if(eReciever_GetStatus() == READY)
		{
			Reciever_GetStringCopy(cReceivedString);
			DecodeMsg(cReceivedString);
			if ( (ucTokenNr != 0) && (asToken[0].eType == KEYWORD) )
			{
				switch (asToken[0].uValue.eKeyword)
				{
					case CALLIB:
						ServoCallib();
					case GOTO:
						if (asToken[1].eType == NUMBER)
						{
							uiDesiredPosition = asToken[1].uValue.uiNumber;
							ServoGoTo(uiDesiredPosition);
						}
				}
			}
		}
	}
}