#include "myString.h"

// Lancuchy znakowe - operacje proste
void CopyString(char pcSource[], char pcDestination[])
{
    unsigned char ucCharCounter;
    for (ucCharCounter=0; (pcSource[ucCharCounter] != NULL); ucCharCounter++)
    {
        pcDestination[ucCharCounter] = pcSource[ucCharCounter];
    }
    pcDestination[ucCharCounter]='\0';
}

enum CompResult eCompareString(char pcStr1[], char pcStr2[])
{
    unsigned char ucCharCounter;
    for (ucCharCounter=0; (pcStr1[ucCharCounter] != NULL) ||  (pcStr2[ucCharCounter] != NULL); ucCharCounter++)
    {
        if(pcStr1[ucCharCounter] != pcStr2[ucCharCounter])
        {
            return DIFFERENT;
        }
    }
    return EQUAL;
}

void AppendString (char pcSourceStr[],char pcDestinationStr[])
{
    unsigned char ucCharCounter;
    for (ucCharCounter=0; (pcDestinationStr[ucCharCounter] != NULL); ucCharCounter++)
    {
        ;
    }
    CopyString(pcSourceStr,&pcDestinationStr[ucCharCounter]);
}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar)
{
    unsigned char ucCharCounter;
    for (ucCharCounter=0; (pcString[ucCharCounter] != NULL); ucCharCounter++)
    {
        if(pcString[ucCharCounter]==cOldChar)
            pcString[ucCharCounter]=cNewChar;
    }
}

// Lancuchy znakowe - konwersje
void UIntToHexStr (unsigned int uiValue, char pcStr[])
{
	  unsigned char ucNibbleCounter;
    unsigned int uiNibbleVal=uiValue;
    
		pcStr[0]='0';
    pcStr[1]='x';
    pcStr[6]='\0';

    for (ucNibbleCounter=0; ucNibbleCounter<4; ucNibbleCounter++)
    {
        uiNibbleVal=uiValue;
        uiNibbleVal=(((uiNibbleVal>>(ucNibbleCounter*4))&0xF));
        if (uiNibbleVal<=9)
        {
            pcStr[5-ucNibbleCounter]=(char)(uiNibbleVal+'0');
        }
        else
        {
            pcStr[5-ucNibbleCounter]=(char)(uiNibbleVal-10+'A');
        }
    }
}

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue)
{
		unsigned char ucCharCounter;
    char cTempChar;
    *puiValue=0;
	
		if ((pcStr[0] != '0')||(pcStr[1]!='x')||(pcStr[2]=='\0'))
    {
        return ERROR;
    }

    for (ucCharCounter=2; pcStr[ucCharCounter]!='\0'; ucCharCounter++)
    {
        cTempChar = pcStr[ucCharCounter];

        if (ucCharCounter>6)
        {
            return ERROR;
        }
        else if ((cTempChar>='0')&&(cTempChar<='9'))
        {
            cTempChar=cTempChar-'0';
        }
        else if ((cTempChar>='A')&&(cTempChar<='F'))
        {
            cTempChar=cTempChar-'A'+10;
        }
        else
        {
            return ERROR;
        }
        *puiValue=((*puiValue<<4)|(int)(cTempChar));
    }
    return OK;
}

void AppendUIntToString (unsigned int uiValue, char pcDestinationStr[])
{
    unsigned char ucCharCounter;
    for(ucCharCounter=0; pcDestinationStr[ucCharCounter]!='\0'; ucCharCounter++)
    {
        ;
    }
    UIntToHexStr (uiValue, &pcDestinationStr[ucCharCounter]);
}  

