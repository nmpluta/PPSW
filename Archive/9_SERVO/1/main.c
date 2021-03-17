// 9.1
#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

#define DETECTOR_bm (1<<10)
#define BUTTON3_bm (1<<7)

enum DetectorState {ACTIVE, INACTIVE};
enum LedState{STOP, LED_LEFT, LED_RIGHT, CALLIB};
enum LedState eLedState = CALLIB;

void DetectorInit(void)
{
	IO0DIR=IO0DIR&(~DETECTOR_bm);
}

enum DetectorState eReadDetector(void)
{
	if((IO0PIN & BUTTON3_bm) == 0)
	{
		return ACTIVE;
	}
	
	else
	{
		return INACTIVE;
	}
}

void Automat()
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
			
			case CALLIB:
			{
				if(eReadDetector() == INACTIVE)
				{
					LedStepLeft();
					eLedState = CALLIB;
				}
				else 
				{
					eLedState = STOP;
				}
			}
			break;
		}
}


int main (){
	
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	DetectorInit();
	
	Timer0Interrupts_Init(20000,&Automat);
	
	while(1)
	{
	 	iMainLoopCtr++;
	}
}
