// 12.5
#include "uart.h"
#include "keyboard.h"
#include "servo.h"
#include "myString.h"
#include "command_decoder.h"
#include "timer_interrupts.h"
#include <LPC21xx.H>


struct Watch 
{
	unsigned char ucMinutes, ucSecconds;
	unsigned char fSeccondsValueChanged, fMinutesValueChanged;
};
struct Watch sWatch;

void WatchUpdate()
{	
	sWatch.ucSecconds++;
	sWatch.fSeccondsValueChanged = 1;
	
	if(sWatch.ucSecconds == 5) 
		{
		sWatch.ucSecconds = 0;
		sWatch.ucMinutes++;
		sWatch.fMinutesValueChanged = 1;
		}
		
	else if(sWatch.ucMinutes == 5)
		{
		sWatch.ucMinutes = 0;
		}
}

int main ()
{	
	char cTimeArray[TRANSMITER_SIZE];
	
	UART_InitWithInt(9600);
	Timer0Interrupts_Init(100000,&WatchUpdate);
	while(1)
	{
		if (eTransmiter_GetStatus() == FREE)
			{
			if(sWatch.fSeccondsValueChanged == 1)
				{
					sWatch.fSeccondsValueChanged = 0;
					CopyString("sec ",cTimeArray);
					AppendUIntToString(sWatch.ucSecconds,cTimeArray);
					AppendString("\n",cTimeArray);
					Transmiter_SendString(cTimeArray);
				}
				
			else if(sWatch.fMinutesValueChanged == 1)
				{
					sWatch.fMinutesValueChanged = 0;
					CopyString("min ",cTimeArray);
					AppendUIntToString(sWatch.ucMinutes,cTimeArray);
					AppendString("\n",cTimeArray);
					Transmiter_SendString(cTimeArray);
				}
			}
	}
}
