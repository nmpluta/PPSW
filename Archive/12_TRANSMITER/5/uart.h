#define RECIEVER_SIZE  15
#define TRANSMITER_SIZE 12

enum eTransmiterStatus {FREE, BUSY};
enum eRecieverStatus {EMPTY, READY, OVERFLOW};

char Transmiter_GetCharacterFromBuffer(void);
void Transmiter_SendString(char cString[]);
enum eTransmiterStatus eTransmiter_GetStatus(void);

//void Reciever_PutCharacterToBuffer(char cCharacter);
enum eRecieverStatus eReciever_GetStatus(void);
void Reciever_GetStringCopy(char * ucDestination);

void UART_InitWithInt(unsigned int uiBaudRate);

