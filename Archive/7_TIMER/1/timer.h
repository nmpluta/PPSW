#define COUNTER_ENABLE (1<<0)
#define COUNTER_RESET (1<<1)

void InitTimer0(void);
void WaitOnTimer0(unsigned int uiTime);
