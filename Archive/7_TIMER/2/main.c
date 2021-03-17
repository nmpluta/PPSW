// 7.2
#include "led.h"
#include "timer.h"

int main()
{
	while(1)
	{
		LedInit();
		InitTimer0Match0(100000);
		while(1)
		{
			LedStepLeft();
			WaitOnTimer0Match0();
		}
	}
}
