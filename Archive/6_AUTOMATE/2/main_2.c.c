// 6.2
#include "led.h"

void Delay(unsigned uiMiliSecs)
{
	unsigned long ulCounter;
	for (ulCounter=0; ulCounter<(5455*uiMiliSecs); ulCounter++)
	{
		;
	}
}

int main()
{	
	enum LedState{STATE0, STATE1, STATE2, STATE3, STATE4, STATE5};
	enum LedState eLedState = STATE0;

	LedInit();

	while(1)
	{
		switch(eLedState)
		{
			case STATE0:
				eLedState = STATE1;
				LedStepRight();
				break;
			
			case STATE1:
				eLedState = STATE2;
				LedStepRight();
				break;

			case STATE2:
				eLedState = STATE3;
				LedStepRight();
				break;
			
			case STATE3:
				eLedState = STATE4;
				LedStepLeft();
				break;
			
			case STATE4:
				eLedState = STATE5;
				LedStepLeft();
				break;
			
			case STATE5:
				eLedState = STATE0;
				LedStepLeft();
				break;
		}
	Delay(500);
	}
}
