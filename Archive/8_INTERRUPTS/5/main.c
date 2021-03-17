// 8.5
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

void Automat(){
	
	enum LedState{STOP, LED_LEFT, LED_RIGHT};
	static enum LedState eLedState = STOP;
	
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
		}
}


int main (){
	
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	
	Timer0Interrupts_Init(20000,&Automat);					// 20000us = (1/50Hz)
	
	while(1){
	 	iMainLoopCtr++;
	}
}
