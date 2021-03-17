enum StepState {LEFT, RIGHT};

void LedInit(void);
void LedOn(unsigned char ucLedIndeks);
void LedStep(enum StepState eDirection);
void LedStepLeft(void);
void LedStepRight(void);
