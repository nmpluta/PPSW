// 6.3
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

	unsigned uiStepCounter=0; 

	LedInit();

	while(1)
	{
		switch(eLedState)
		{
			case LED_LEFT:
				uiStepCounter++;
				if(uiStepCounter > 3)
				{
					uiStepCounter = 0;
					eLedState = LED_RIGHT;
				}
				else
				{
					LedStepLeft();
				}
				break;

			case LED_RIGHT:
				uiStepCounter++;
				if(uiStepCounter > 3)
				{
					uiStepCounter = 0;
					eLedState = LED_LEFT;
				}
				else
				{
					LedStepRight();
				}
				break;
		}
	Delay(500);
	}
}
