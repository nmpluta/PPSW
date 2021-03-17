#define RECIEVER_SIZE  15
#define TRANSMITER_SIZE 10

enum eTransmiterStatus {FREE, BUSY};
enum eRecieverStatus {EMPTY, READY, OVERFLOW};

char Transmiter_GetCharacterFromBuffer(void);
void Transmiter_SendString(unsigned char cString[]);
enum eTransmiterStatus eTransmiter_GetStatus(void);

//void Reciever_PutCharacterToBuffer(char cCharacter);
enum eRecieverStatus eReciever_GetStatus(void);
void Reciever_GetStringCopy(char * ucDestination);

void UART_InitWithInt(unsigned int uiBaudRate);

