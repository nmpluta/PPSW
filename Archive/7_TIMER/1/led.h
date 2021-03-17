enum StepState {LEFT, RIGHT};
#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

void LedInit(void);
void LedOn(unsigned char ucLedIndeks);
void LedStep(enum StepState eDirection);
void LedStepLeft(void);
void LedStepRight(void);
