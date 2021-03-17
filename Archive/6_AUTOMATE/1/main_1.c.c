// 6.1
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
	enum LedState{LED_LEFT, LED_RIGHT};
	enum LedState eLedState = LED_LEFT;

	LedInit();

	while(1)
	{
		switch(eLedState)
		{
			case LED_LEFT:
				eLedState = LED_RIGHT;
				LedStepRight();
				break;
			
			case LED_RIGHT:
				eLedState = LED_LEFT;
				LedStepLeft();
				break;
		}
	Delay(500);
	}
}
