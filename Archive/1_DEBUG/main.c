#include <LPC21xx.H>
int iPlusCounter;
int iMinusCounter;
int iLoopCtr;
int main()
{
	iPlusCounter=10;
	iMinusCounter=0;
	for (iLoopCtr=0;iLoopCtr<5;iLoopCtr++)
	{
		iPlusCounter=iPlusCounter+3;
		iMinusCounter=iMinusCounter-3;
	}
}