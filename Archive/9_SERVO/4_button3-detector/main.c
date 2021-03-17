// 9.4
#include "keyboard.h"
#include "servo.h"

int main ()
{	
	KeyboardInit();
	ServoInit(5);
	
	while(1)
	{
		if(eKeyboardRead()==BUTTON_0)
		{
			//ServoCallib();
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
	}
}
