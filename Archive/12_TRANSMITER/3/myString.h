#define NULL '\0'
#define DELIMETER_CHAR ' '
#define TERMINATOR '\r'

enum CompResult {DIFFERENT, EQUAL};
enum Result {OK, ERROR};

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue);
enum CompResult eCompareString(char pcStr1[], char pcStr2[]);
void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar);
void CopyString(char pcSource[], char pcDestination[]);
