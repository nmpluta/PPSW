// 6.8 assignment
#include "led.h"
#include "keyboard.h"

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
				else if ( ucBlinkingCounter < 10 )
				{
					eLedState = LED_BLINKING;
					LedsBlink(100);
					ucBlinkingCounter++;
				}
				else 
				{
					eLedState = STOP;
				}
			}
			break;
		}
	Delay(100);
	}
}
