#include "timer_interrupts.h"
#include "uart.h"
#include "string.h"
#include "command_decoder.h"

struct Watch {
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
		
	else if(sWatch.ucMinutes == 60)
		{
		sWatch.ucMinutes = 0;
		}
}


int main ()
{	
	char cTransmiterTab[TRANSMITER_SIZE];
	char cReceivedString[RECIEVER_SIZE];
	unsigned char fDecodeCalcToken;
	
	UART_InitWithInt(9600);
	Timer0Interrupts_Init(1000000,&WatchUpdate);

	while(1)
	{	
		if((eReciever_GetStatus() == READY))
		{
			Reciever_GetStringCopy( cReceivedString );
			DecodeMsg( cReceivedString );
		
			if ( (asToken[0].eType == KEYWORD) && (asToken[1].eType == NUMBER) )			// dolozyc id, unknowncommand
			{
					fDecodeCalcToken=1;
			}
		}
		
		if((Transmiter_GetStatus() == FREE))
		{/*
			if(sWatch.fSeccondsValueChanged==1)
			{
				sWatch.fSeccondsValueChanged=0;
				CopyString("sec ",cTransmiterTab);
				AppendUIntToString(sWatch.ucSecconds,cTransmiterTab);
				AppendString("\n",cTransmiterTab);
				Transmiter_SendString(cTransmiterTab);	
			}
			else if(sWatch.fMinutesValueChanged==1)
			{
				sWatch.fMinutesValueChanged=0;
				CopyString("min ",cTransmiterTab);
				AppendUIntToString(sWatch.ucMinutes,cTransmiterTab);
				AppendString("\n",cTransmiterTab);
				Transmiter_SendString(cTransmiterTab);	
			}  */
			if (fDecodeCalcToken==1)
			{
				fDecodeCalcToken=0;
				CopyString("calc ",cTransmiterTab);
				AppendUIntToString((asToken[1].uValue.uiNumber)*2, cTransmiterTab);
				AppendString("\n",cTransmiterTab);
				Transmiter_SendString(cTransmiterTab);
			}			
		}
	}
}

// id LPCx2109
// pusty string unknowncommand flaga - 1-0 
