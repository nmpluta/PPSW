#include <LPC21xx.H>
#include "keyboard.h"

#define BUTTON0_bm 0x00000010
#define BUTTON1_bm 0x00000040
#define BUTTON2_bm 0x00000020
#define BUTTON3_bm 0x00000080

void KeyboardInit(void)
{
	IO0DIR=IO0DIR&(~(BUTTON0_bm|BUTTON1_bm|BUTTON2_bm|BUTTON3_bm));
}

enum KeyboardState eKeyboardRead(void)
{
	if ((IO0PIN&BUTTON0_bm) == 0)
		return BUTTON_0;
	
	else if ((IO0PIN&BUTTON1_bm) == 0)
		return BUTTON_1;
	
	else if ((IO0PIN&BUTTON2_bm) == 0)
		return BUTTON_2;
	
	else if ((IO0PIN&BUTTON3_bm) == 0)
		return BUTTON_3;
	
	else 
		return RELASED;
}
