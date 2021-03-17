enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3}; 
#define BUTTON0_bm (1<<4)
#define BUTTON1_bm (1<<6)
#define BUTTON2_bm (1<<5)
#define BUTTON3_bm (1<<7)

void KeyboardInit(void);
enum KeyboardState eKeyboardRead(void);
