#define COUNTER_ENABLE (1<<0)
#define COUNTER_RESET (1<<1)
#define MR0_INTERRUPT (1<<0) 
#define MR0_RESET (1<<1)	
#define MR0_STOP (1<<2)	
#define MR0_INTERRUPT_FLAG (1<<0) 

void InitTimer0(void);
void WaitOnTimer0(unsigned int uiMicroDelay);
void InitTimer0Match0(unsigned int uiMicroDelay);
void WaitOnTimer0Match0(void);
