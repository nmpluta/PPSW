#include <stdio.h>
#include <stdlib.h>
#define TRANSMITER_SIZE 15
#define TERMINATOR '\r'

void CopyString(char pcSource[], char pcDestination[])
{
    unsigned char ucCharCounter;
    for (ucCharCounter=0; (pcSource[ucCharCounter] != NULL); ucCharCounter++)
    {
        pcDestination[ucCharCounter] = pcSource[ucCharCounter];
    }
    pcDestination[ucCharCounter]='\0';
}

enum eTransmiterStatus {FREE, BUSY};
struct TransmiterBuffer
{
	char cData[TRANSMITER_SIZE];
	enum eTransmiterStatus eStatus;
	unsigned char fLastCharacter;
	unsigned char cCharCtr;
};
struct TransmiterBuffer sTransmiterBuffer;

char Transmiter_GetCharacterFromBuffer(void)
{
	char cCurrentChar = sTransmiterBuffer.cData[sTransmiterBuffer.cCharCtr];
	if (cCurrentChar != NULL)
	{
		sTransmiterBuffer.cCharCtr++;
		return cCurrentChar;
	}
	else
	{
		if (sTransmiterBuffer.fLastCharacter == 0)
		{
			sTransmiterBuffer.fLastCharacter = 1;
            return 'T';                     // return TERMINATOR;
		}
		else
		{
			sTransmiterBuffer.fLastCharacter = 0;
			return 'N';                     // return NULL;
		}
	}
}

int main()
{
    CopyString("Ala",sTransmiterBuffer.cData);
    printf(sTransmiterBuffer.cData);
    printf("\n");
    printf("%c\n",Transmiter_GetCharacterFromBuffer());
    printf("%c\n",Transmiter_GetCharacterFromBuffer());
    printf("%c\n",Transmiter_GetCharacterFromBuffer());
    printf("%c\n",Transmiter_GetCharacterFromBuffer());
    printf("%c\n",Transmiter_GetCharacterFromBuffer());

    return 0;
}
