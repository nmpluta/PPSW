#include "myString.h"
#include "command_decoder.h"


struct Keyword asKeywordList[MAX_KEYWORD_NR]=
{
	{CALLIB, "callib"},
	{GOTO, "goto"},
};

struct Token asToken[MAX_TOKEN_NR];
unsigned char ucTokenNr;

/*
asKeywordList[] // uzywana przez bStringToCommand
asToken[] // wypelniana przez DecodeMsg na podstawie cUartRxBuffer i asCommandList
ucTokenNr // liczba tokenów w zdekodowanym komunikacie
*/

unsigned char ucFindTokensInString (char *pcString)
{
	enum StringState {TOKEN, DELIMETER};
	enum StringState eState = DELIMETER;

	unsigned char ucStringCounter = 0;
	char cCurrentChar;
	ucTokenNr = 0;

	for(ucStringCounter = 0; ;ucStringCounter++)
	{
		cCurrentChar = pcString[ucStringCounter];
		switch(eState)
		{
			case DELIMETER:
				if (cCurrentChar == DELIMETER_CHAR)
				{
					eState = DELIMETER;
				}
				else if (cCurrentChar == NULL)
				{
					return ucTokenNr;
				}
				else if (ucTokenNr < MAX_TOKEN_NR)
				{
					eState = TOKEN;
					asToken[ucTokenNr].uValue.pcString = &pcString[ucStringCounter];
					ucTokenNr++;
				}
				else
				{
					return ucTokenNr;
				}
				break;

			case TOKEN:
				if (cCurrentChar == DELIMETER_CHAR)
				{
					eState = DELIMETER;
				}
				else if (cCurrentChar == NULL)
				{
					return ucTokenNr;
				}
				else
				{
					eState = TOKEN;
				}
				break;
		}
	}
}

enum Result eStringToKeyword (char pcStr[],enum KeywordCode *peKeywordCode)
{
	unsigned uiKeywordCounter;
	for (uiKeywordCounter=0; uiKeywordCounter < MAX_KEYWORD_NR; uiKeywordCounter++)
	{
		if(eCompareString(pcStr, asKeywordList[uiKeywordCounter].cString) == EQUAL)
		{
			*peKeywordCode = asKeywordList[uiKeywordCounter].eCode;
			return OK;
		}
	}
	return ERROR;
}

void DecodeTokens(void)
{
	unsigned char ucTokenCounter;
	enum KeywordCode eKeyword;
	unsigned int uiDecimalNumber;

	for (ucTokenCounter=0; ucTokenCounter < ucTokenNr; ucTokenCounter++)
	{
		if(	eStringToKeyword(asToken[ucTokenCounter].uValue.pcString, &eKeyword) == OK )
		{
			asToken[ucTokenCounter].eType = KEYWORD;
			asToken[ucTokenCounter].uValue.eKeyword = eKeyword;
		}
		else if ( eHexStringToUInt(asToken[ucTokenCounter].uValue.pcString, &uiDecimalNumber) == OK)
		{
			asToken[ucTokenCounter].eType = NUMBER;
			asToken[ucTokenCounter].uValue.uiNumber = uiDecimalNumber;
		}
		else
		{
			asToken[ucTokenCounter].eType = STRING;
		}
	}
}

void DecodeMsg (char *pcString)
{
	ucTokenNr = ucFindTokensInString(pcString);
	ReplaceCharactersInString(pcString, DELIMETER_CHAR, NULL);
	DecodeTokens();
}

