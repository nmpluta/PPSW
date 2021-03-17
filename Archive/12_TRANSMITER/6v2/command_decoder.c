#include "string.h"
#include "command_decoder.h"

struct Keyword asKeywordList[MAX_KEYWORD_NR]=
	{
		{CALC, "calc"}
	};
struct Token asToken[MAX_TOKEN_NR];

unsigned char ucTokenNr;
	
unsigned char ucFindTokensInString(char *pcString){
	
	enum LedState { TOKEN, DELIMITER};
	enum LedState eState = DELIMITER;
	
	unsigned char ucTokenCounter = 0;
	unsigned char ucCharCounter = 0;
	char cCurrentChar;
	
	for(ucCharCounter=0; pcString[ucCharCounter] != NULL; ucCharCounter++){
		cCurrentChar = pcString[ucCharCounter];
		switch(eState){
			case DELIMITER: 	
				if(cCurrentChar == DELIMITER_CHAR){
					eState = DELIMITER;
				}else if(ucTokenCounter < MAX_TOKEN_NR){
					eState = TOKEN;
					asToken[ucTokenCounter].uValue.pcString = pcString + ucCharCounter; 
					ucTokenCounter++;
				}else{
					return(ucTokenCounter);
				}
				break;
			case TOKEN: 
				if(cCurrentChar!= DELIMITER_CHAR){
					eState = TOKEN;
				}else{
					eState = DELIMITER;
				}
				break;
		}	
	}
	return(ucTokenCounter);
}

enum Result eStringToKeyword(char pcStr[], enum KeywordCode *peKeywordCode){
	
	unsigned char ucKeywordIndex;
	
	for(ucKeywordIndex=0; ucKeywordIndex < MAX_KEYWORD_NR; ucKeywordIndex++){
		if(eCompareString(pcStr, asKeywordList[ucKeywordIndex].cString) == EQUAL){
			*peKeywordCode = asKeywordList[ucKeywordIndex].eCode;
			return(OK);
		}
	}
	return(ERROR);
}

void DecodeTokens(void){
	
	unsigned int uiNumber;
	unsigned char ucTokenIndex;
	enum KeywordCode eKeyword;
	struct Token SingleToken;
	
	for(ucTokenIndex=0; ucTokenIndex < ucTokenNr; ucTokenIndex++)
	{					// zamiana asToken[ucTokenIndex] na cos
		SingleToken = asToken[ucTokenIndex];
		if((eStringToKeyword (SingleToken.uValue.pcString, &eKeyword))== OK)
		{
			SingleToken.eType = KEYWORD;
			SingleToken.uValue.eKeyword=eKeyword;
		}
		else if((eHexStringToUInt(SingleToken.uValue.pcString,&uiNumber))== OK)
		{
			SingleToken.eType = NUMBER;
			SingleToken.uValue.uiNumber = uiNumber;		
		}
		else
		{
			SingleToken.eType = STRING;
		}
	}
}

void DecodeMsg(char *pcString){

	ucTokenNr = ucFindTokensInString (pcString);
	ReplaceCharactersInString(pcString,' ',NULL);
	DecodeTokens();
}
