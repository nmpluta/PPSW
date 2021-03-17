#include "keyboard.h"
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
	
	if(sWatch.ucSecconds == 60) 
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


int main (){
	
	char cTab[TRANSMITER_SIZE];
	char cOdebranyString[RECIEVER_SIZE];
	unsigned char fDecodeCalcToken;
	
	UART_InitWithInt(9600);
	Timer0Interrupts_Init(10000000,&WatchUpdate);

	while(1){
		
		if((eReciever_GetStatus() == READY))
		{
			Reciever_GetStringCopy( cOdebranyString );
			DecodeMsg( cOdebranyString );
		
			if ( (ucTokenNr == 2) && (asToken[0].eType == KEYWORD) && (asToken[1].eType == NUMBER) )
			{
					fDecodeCalcToken=1;
			}
		}
		
		if((Transmiter_GetStatus() == FREE))
		{
			if(sWatch.fSeccondsValueChanged==1)
			{
				sWatch.fSeccondsValueChanged=0;
				CopyString("sec ",cTab);
				AppendUIntToString(sWatch.ucSecconds,cTab);
				AppendString("\n",cTab);
				Transmiter_SendString(cTab);	
			}
			else if(sWatch.fMinutesValueChanged==1)
			{
				sWatch.fMinutesValueChanged=0;
				CopyString("min ",cTab);
				AppendUIntToString(sWatch.ucMinutes,cTab);
				AppendString("\n",cTab);
				Transmiter_SendString(cTab);	
			}
			else	if (fDecodeCalcToken==1)
			{
				fDecodeCalcToken=0;
				CopyString("calc ",cTab);
				AppendUIntToString((asToken[1].uValue.uiNumber)*2, cTab);
				AppendString("\n",cTab);
				Transmiter_SendString(cTab);
			}			
		}
	}
}

