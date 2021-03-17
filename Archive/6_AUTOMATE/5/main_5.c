// 6.5
#include "led.h"
#include "keyboard.h"

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
	KeyboardInit();

	while(1)
	{
		switch(eLedState)
		{
			case LED_LEFT:
			{
				if( eKeyboardRead() == BUTTON_1 )
				{
					eLedState = LED_RIGHT;
				}
			}
			break;

			case LED_RIGHT:
				if( eKeyboardRead() == BUTTON_0 )
				{
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
