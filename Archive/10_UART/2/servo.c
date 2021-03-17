#include <LPC21xx.H>
#include "led.h"
#include "timer_interrupts.h"
#include "servo.h"

#define DETECTOR_bm (1<<10)

enum DetectorState {ACTIVE, INACTIVE};
enum ServoState {CALLIB, IDLE, IN_PROGRESS, OFFSET};

struct Servo
{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
	unsigned int uiOffset;
};
struct Servo sServo;

/***    FUNKCJE     ***/
void DetectorInit(void)
{
	IO0DIR=IO0DIR & (~DETECTOR_bm);
}

enum DetectorState eReadDetector(void)
{
	if((IO0PIN & DETECTOR_bm) == 0)
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
/***************************/

void Automat()
{
	switch(sServo.eState)
		{
			case CALLIB:
			{
				if ( eReadDetector() == INACTIVE )
				{
					LedStepLeft();
					sServo.eState = CALLIB;
				}
				else
				{
					sServo.uiCurrentPosition = 0;
					sServo.uiDesiredPosition = 0;
					sServo.eState = OFFSET;
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
			
			case OFFSET:
			if( sServo.uiCurrentPosition > sServo.uiOffset ) 
			{
				sServo.uiCurrentPosition = 0;
				sServo.eState = IDLE;
			}
			else 
			{
				LedStepRight();
				sServo.uiCurrentPosition++;
				sServo.eState = OFFSET;
			}
			break;
		}
}

void ServoInit(unsigned int uiServoFrequency)
{
	LedInit();
	DetectorInit();
	Timer0Interrupts_Init((1e6/uiServoFrequency),&Automat);
	ServoCallib();
	sServo.uiOffset = 12; 
}
