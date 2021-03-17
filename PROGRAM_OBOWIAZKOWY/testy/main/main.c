#include <stdio.h>
#include <string.h>

#include "myString.h"
#include "myTokens.h"

void TestOf_CopyString(void)
{
    printf("CopyString\n\n");

    printf("Test 1 - ");
    //string zrodlowy krotszy niz string docelowy
    char Source1[]="Hello world";
    char Destination1[]="---------------------";
    CopyString(Source1, Destination1);
    if (strcmp(Source1, Destination1) == 0) printf("OK\n");
    else printf("Error\n");

    printf("Test 2 - ");
    //string zrodlowy pusty
    char Source2[]="";
    char Destination2[]="12345";
    CopyString(Source2, Destination2);
    if (strcmp(Source2, Destination2) == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 3 - ");
    //ta sama dlugosc stringow
    char Source3[]="abcde";
    char Destination3[]="12345";
    CopyString(Source3, Destination3);
    if (strcmp(Source3, Destination3) == 0)
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_eCompareString(void)
{
    printf("\n\neCompareString\n\n");

    printf("Test 1 - ");
    //takie same stringi o tej samej dlugosci
    if (eCompareString("xyz", "xyz") == EQUAL)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 2 - ");
    //oba stringi puste
    if (eCompareString("", "") == EQUAL)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 3 - ");
    // takie same stringi zawierajace spacje
    if (eCompareString("abc de", "abc de") == EQUAL)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 4 - ");
    //rozne stringi o roznej dlugosci
    if (eCompareString("xyz", "abcde") == DIFFERENT)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 5 - ");
    //pierwszy string pusty
    if (eCompareString("", "abcde") == DIFFERENT)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 6 - ");
    //drugi string pusty
    if (eCompareString("xyz", "") == DIFFERENT)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 7 - ");
    //pierwszy string krotszy
    if (eCompareString("abc", "abcde") == DIFFERENT)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 8 - ");
    //pierwszy string dluzszy
    if (eCompareString("abcdefgh", "abcde") == DIFFERENT)
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_AppendString(void)
{
    printf("\n\nAppendString\n\n");

    printf("Test 1 - ");
    // dwa dowolne stringi
    char cDestination1[]="12345";
    AppendString("6789", cDestination1);
    if (strcmp(cDestination1, "123456789") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 2 - ");
    // string docelowy pusty
    char cDestination2[]="";
    AppendString("6789", cDestination2);
    if (strcmp(cDestination2, "6789") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 3 - ");
    // string doklejany pusty
    char cDestination3[]="12345";
    AppendString("", cDestination3);
    if (strcmp(cDestination3, "12345") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 4 - ");
    // oba stringi puste
    char cDestination4[]="";
    AppendString("", cDestination4);
    if (strcmp(cDestination4, "") == 0)
        printf("OK\n");
    else
        printf("Error\n");

}

void TestOf_ReplaceCharactersInString(void)
{
    printf("\n\nReplaceCharactersInString\n\n");

    printf("Test 1 - ");
    // zamiana malej litery na duza
    char cOriginalString1[] = "aaaaa";
    ReplaceCharactersInString(cOriginalString1, 'a', 'A');
    if (strcmp(cOriginalString1, "AAAAA") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 2 - ");
    // zamiana dowolnego znaku na spacje
    char cOriginalString2[] = "Znak na spacje";
    ReplaceCharactersInString(cOriginalString2,'c',' ');
    if (strcmp(cOriginalString2, "Znak na spa je") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 3 - ");
    // zamiana dowolnego znaku na NULL
    char cOriginalString3[] = "Dowolny znak na NULL";
    ReplaceCharactersInString(cOriginalString3,'o','\0');
    if (strcmp(cOriginalString3, "D\0w\0lny znak na NULL") == 0)
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_UIntToHexStr(void)
{
    printf("\n\nUIntToHexStr\n\n");
    char cHexString[6];

    printf("Test 1 - ");
    // krance przedzialow 0, 9, 10 (A), 15 (F)
    UIntToHexStr(0xFA90, cHexString);
    if (strcmp(cHexString, "0xFA90") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 2 - ");
    // liczba zapisana w hexie w skroconej formie, w stringu zera po 0x
    UIntToHexStr(0x2, cHexString);
    if (strcmp(cHexString, "0x0002") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 3 - ");
    // same zera
    UIntToHexStr(0x0, cHexString);
    if (strcmp(cHexString, "0x0000") == 0)
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_eHexStringToUInt(void)
{
    printf("\n\neHexStringToUInt\n\n");
    unsigned int uiReturnValue;

    printf("Test 1 - ");
    // krance przedzialow 0, 9, 10 (A), 15 (F)
    char cHexString1[]="0xFA90";
    if ( eHexStringToUInt(cHexString1, &uiReturnValue) == OK)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 2 - ");
    // string rozpoczynajacy sie od 0x, ale nie majacy dlugosc 6
    char cHexString2[]="0xAB";
    if ( eHexStringToUInt(cHexString2, &uiReturnValue) == OK)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 3 - ");
    // za krotki string
    char cHexString3[]="0x";
    if ( eHexStringToUInt(cHexString3, &uiReturnValue) == ERROR)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 4 - ");
    // za dlugi string
    char cHexString4[]="0x1234567";
    if ( eHexStringToUInt(cHexString4, &uiReturnValue) == ERROR)
        printf("OK\n");
    else
        printf("Error\n");


    printf("Test 5 - ");
    // poczatek rozny od 0x
    char cHexString5[]="AAFA90";
    if ( eHexStringToUInt(cHexString5, &uiReturnValue) == ERROR)
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_AppendUIntToString(void)
{
    printf("\n\nAppendUIntToString\n\n");

    printf("Test 1 - ");
    //dodawanie do dowolnego stringa
    char cDestination1[]="abcde ";
    AppendUIntToString(0xAF15, cDestination1);
    if (strcmp(cDestination1, "abcde 0xAF15") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 2 - ");
    //dodawanie do pustego stringa
    char cDestination2[]="";
    AppendUIntToString(0x01BB, cDestination2);
    if (strcmp(cDestination2, "0x01BB") == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 3 - ");
    //dodawanie do NULLa
    char cDestination3[]="a \0";
    AppendUIntToString(0x01BB, cDestination3);
    if (strcmp(cDestination3, "a 0x01BB") == 0)
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_ucFindTokensInString(void)
{
    printf("\n\nucFindTokensInString\n\n");

    printf("Test 1 - ");
    // 3 tokeny - maksymalna liczba
    char cTestString1[]="Maximal tokens number";
    if (ucFindTokensInString(cTestString1) == 3)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 2 - ");
    // same delimitry
    char cTestString2[]="     ";
    if (ucFindTokensInString(cTestString2) == 0)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 3 - ");
    // delimiter przed pierwszym tokenem
    char cTestString3[]="  Deliemeter before";
    if (ucFindTokensInString(cTestString3) == 2)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 4 - ");
    // kilka delimiterow pomiedzy tokenami
    char cTestString4[]="Some   delimeters between";
    if (ucFindTokensInString(cTestString4) == 3)
        printf("OK\n");
    else
        printf("Error\n");


    printf("Test 5 - ");
    // przekroczona liczba maksymalnych tokenow
    char cTestString5[]="Maximal tokens number exceeded";
    if (ucFindTokensInString(cTestString5) == MAX_TOKEN_NR)
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_eStringToKeyword(void)
{
    printf("\n\neStringToKeyword\n\n");
    enum KeywordCode peKeywordCode;

    printf("Test 1 - ");
    //slowo kluczowe load
    char cKeywordString1[]="load";
    if (eStringToKeyword(cKeywordString1, &peKeywordCode) == OK)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 2 - ");
    //slowo kluczowe store
    char cKeywordString2[]="store";
    if (eStringToKeyword(cKeywordString2, &peKeywordCode) == OK)
        printf("OK\n");
    else
        printf("Error\n");


    printf("Test 3 - ");
    //slowo kluczowe reset
    char cKeywordString3[]="reset";
    if (eStringToKeyword(cKeywordString3, &peKeywordCode) == OK)
        printf("OK\n");
    else
        printf("Error\n");

    printf("Test 4 - ");
    //string rozny od slowa kluczowego
    char cKeywordString4[]="different";
    if (eStringToKeyword(cKeywordString4, &peKeywordCode) == ERROR)
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_DecodeTokens(void)
{
    printf("\n\nDecodeTokens\n\n");
    char cMessage[]= "0x1AF0 later load";
    unsigned char ucTokenNumber;
    printf("Test 1 - ");
    // uzycie ucFindTokensInString oraz ReplaceCharactersInString co pozwoli nastepnie
    // sprawdziæ przypisania do STRING, KEYWORD, NUMBER oraz ustawiania wskaznikow na poczatek
    ucTokenNumber = ucFindTokensInString(cMessage);
    ReplaceCharactersInString(cMessage,' ', NULL);
    DecodeTokens();
    if ((asToken[0].eType==NUMBER) && (asToken[0].uValue.uiNumber==0x1AF0) &&
    (asToken[1].eType==STRING) && (&cMessage[7]==asToken[1].uValue.pcString) &&
    (asToken[2].eType==KEYWORD) && (asToken[2].uValue.eKeyword==LD))
        printf("OK\n");
    else
        printf("Error\n");
}

void TestOf_DecodeMsg()
{

    char cMessage[]="0x1AF0 later load";

    printf("\n\nDecodeMsg\n\n");

    printf("Test 1 - ");
	// sprawdzenie poszczegolnych wartosci struktury asToken[3]
    DecodeMsg(cMessage);
    if ((asToken[0].eType==NUMBER) && (asToken[0].uValue.uiNumber==0x1AF0) &&
    (asToken[1].eType==STRING) && (&cMessage[7]==asToken[1].uValue.pcString) &&
    (asToken[2].eType==KEYWORD) && (asToken[2].uValue.eKeyword==LD))
        printf("OK\n");
    else
        printf("Error\n");
}

int main()
{
    printf("TESTY FUNKCJI DO OPERACJI NA STRINGACH \n\n\n");
    TestOf_CopyString();
    TestOf_eCompareString();
    TestOf_AppendString();
    TestOf_ReplaceCharactersInString();
    TestOf_UIntToHexStr();
    TestOf_eHexStringToUInt();
    TestOf_AppendUIntToString();

    printf("\n\n\n");
    printf("TESTY FUNKCJI DO DEKODOWANIA KOMUNIKATOW\n ");
    TestOf_ucFindTokensInString();
    TestOf_eStringToKeyword();
    TestOf_DecodeTokens();
    TestOf_DecodeMsg();

    return 0;
}
