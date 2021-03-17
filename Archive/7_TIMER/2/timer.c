#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE (1<<0)
#define COUNTER_RESET (1<<1)
#define MR0_INTERRUPT (1<<0) 
#define MR0_RESET (1<<1)		
#define MR0_INTERRUPT_FLAG (1<<0) 

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
	T0MCR = T0MCR | (MR0_INTERRUPT|MR0_RESET);	// 
	T0TCR = T0TCR|COUNTER_RESET; 
	T0TCR = COUNTER_ENABLE;	
}

void WaitOnTimer0Match0(void)
{
	while((T0IR&MR0_INTERRUPT_FLAG) == 0x0);
	T0IR = MR0_INTERRUPT_FLAG;	//
}
