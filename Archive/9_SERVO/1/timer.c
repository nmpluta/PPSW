#include <LPC21xx.H>
#include "timer.h"

void InitTimer0(void)
{
	T0TCR = COUNTER_ENABLE;
}

void WaitOnTimer0(unsigned int uiMicroDelay)
{
	T0TCR = T0TCR|COUNTER_RESET;
	T0TCR = T0TCR & (~COUNTER_RESET);
	while(T0TC < (15*uiMicroDelay));
}

void InitTimer0Match0(unsigned int uiMicroDelay)
{
	T0MR0 = 15*uiMicroDelay;
	T0MCR = T0MCR | (MR0_INTERRUPT|MR0_RESET|MR0_STOP);
	T0TCR = T0TCR|COUNTER_RESET;
	T0TCR = T0TCR & (~COUNTER_RESET);
	T0TCR = COUNTER_ENABLE;
}

void WaitOnTimer0Match0(void)
{
	while((T0IR&MR0_INTERRUPT_FLAG) == 0x0);
	T0IR = T0IR|MR0_INTERRUPT_FLAG;
	T0TCR = COUNTER_ENABLE;
}
