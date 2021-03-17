#include <LPC21xx.H>
#include "timer.h"

void InitTimer0(void)
{
	T0TCR = COUNTER_ENABLE;
}

void WaitOnTimer0(unsigned int uiTime)
{
	T0TCR = T0TCR|COUNTER_RESET;
	T0TCR = T0TCR&(~COUNTER_RESET);
	while(T0TC < (15*uiTime));
}
