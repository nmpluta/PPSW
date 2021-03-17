// 6 assigment
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
	enum LedState{STOP, LED_LEFT, LED_RIGHT, LED_BLINKING};
	enum LedState eLedState = STOP;
	unsigned char ucBlinkingCounter = 0;

	LedInit();
	KeyboardInit();

	while(1)
	{
		switch(eLedState)
		{
			case STOP:
			{
				if ( eKeyboardRead() == BUTTON_0 )
				{
					eLedState = LED_LEFT;
				}
				else if ( eKeyboardRead() == BUTTON_2 )
				{
					eLedState = LED_RIGHT;
				}
				else if ( eKeyboardRead() == BUTTON_3 )
				{
					ucBlinkingCounter = 0;
					eLedState = LED_BLINKING;
				}
				else
				{
					eLedState = STOP;
				}
			}
			break;
			
			case LED_LEFT:
			{
				if ( eKeyboardRead() == BUTTON_1 )
				{
					eLedState = STOP;
				}
				else
				{
					eLedState = LED_LEFT;
					LedStepLeft();
				}
			}
			break;

			case LED_RIGHT:
			{
				if( eKeyboardRead() == BUTTON_1)
				{
					eLedState = STOP;
				}
				else
				{
					eLedState = LED_RIGHT;
					LedStepRight();
				}
			}
			break;
			
			case LED_BLINKING:
			{
				if( eKeyboardRead() == BUTTON_1)
				{
					eLedState = STOP;
				}
				else if ( ucBlinkingCounter > 20 )
				{
					eLedState = STOP;
				}
				else 
				{
					if( (ucBlinkingCounter%2) == 0 )
					{
						LedOn(1);
					}
					else 
					{
						LedOn(5);
					}
					eLedState=LED_BLINKING;
					ucBlinkingCounter++;
				}
			break;
			}
		}
	Delay(100);
	}
}
