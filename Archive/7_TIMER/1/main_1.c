// 7.1
#include "led.h"
#include "keyboard.h"
#include "timer.h"

int main()
{
	while(1)
	{
		LedInit();
		InitTimer0();
		while(1)
		{
			LedStepLeft();
			WaitOnTimer0(100000);
		}
	}
}
