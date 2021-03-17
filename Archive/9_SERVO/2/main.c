// 9.2
#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

#define DETECTOR_bm (1<<10)
#define BUTTON3_bm (1<<7)

enum DetectorState {ACTIVE, INACTIVE};
enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo
{
enum ServoState eState;
unsigned int uiCurrentPosition;
unsigned int uiDesiredPosition;
};

struct Servo sServo;

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
	switch(sServo.eState)
		{
			case CALLIB:
			{
				sServo.uiCurrentPosition = 0;
				sServo.uiDesiredPosition = 0;
				if ( eReadDetector() == INACTIVE )
				{
					LedStepLeft();
					sServo.eState = CALLIB;
				}
				else
				{
					sServo.eState = IDLE;
				}
			}
			break;
			
			case IDLE:
			{
				if ( sServo.uiCurrentPosition == sServo.uiDesiredPosition )
				{
					sServo.eState = IDLE;
				}
				else
				{
					sServo.eState = IN_PROGRESS;
				}
			}
			break;

			case IN_PROGRESS:
			{
				if( sServo.uiCurrentPosition < sServo.uiDesiredPosition )
				{
					LedStepRight();
					sServo.uiCurrentPosition++;
					sServo.eState = IN_PROGRESS;
				}
				else if ( sServo.uiCurrentPosition > sServo.uiDesiredPosition )
				{
					LedStepLeft();
					sServo.uiCurrentPosition--;
					sServo.eState = IN_PROGRESS;
				}
				else
				{
					sServo.eState = IDLE;
				}
			}
			break;
		}
}

int main ()
{	
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	DetectorInit();
	
	Timer0Interrupts_Init(200000,&Automat);
	
	while(1)
	{
		if(eKeyboardRead()==BUTTON_0)
		{
			//sServo.eState = CALLIB;
			sServo.uiDesiredPosition = 12;
		}
		if(eKeyboardRead()==BUTTON_1)
		{
			sServo.uiDesiredPosition = 24;
		}
		if(eKeyboardRead()==BUTTON_2)
		{
			sServo.uiDesiredPosition = 36;
		}
	 	iMainLoopCtr++;
	}
}
