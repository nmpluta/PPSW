// 9.3
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

void ServoCallib(void)
{
	sServo.eState = CALLIB;
	while(eReadDetector() != ACTIVE)
	{
		;
	}
}

void ServoGoTo(unsigned int uiPosition)
{
	sServo.uiDesiredPosition = uiPosition;
	sServo.eState = IN_PROGRESS;
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

void ServoInit(unsigned int uiServoFrequency)
{
	Timer0Interrupts_Init((1e6/uiServoFrequency),&Automat);
	LedInit();
	DetectorInit();
	ServoCallib();
}

int main ()
{	
	unsigned int iMainLoopCtr;
	
	KeyboardInit();
	ServoInit(5);
	
	while(1)
	{
		if(eKeyboardRead()==BUTTON_0)
		{
			ServoGoTo(12);
		}
		else if(eKeyboardRead()==BUTTON_1)
		{
			ServoGoTo(24);
		}
		else if(eKeyboardRead()==BUTTON_2)
		{
			ServoGoTo(36);
		}
		else 
		{
			;
		}
	 	iMainLoopCtr++;
	}
}
