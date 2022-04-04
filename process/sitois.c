#include <stdio.h>
#include "../include/def.h"

#define SIZE_BIG 1024

#define strcopy(_T, _S) {\
	int _i = 0;\
	for (char *_t = _T, *_s = _S; (*(_t + _i) = *(_s + _i)); ++_i)\
		;\
}


int stoi(char *numstr)
{
	int number = 0;
	sscanf(numstr, "%d", &number);
	return number;
}


char *itos(int number)
{
	static char numstr[12];
	sprintf(numstr, "%d", number);
	return numstr;
}


char *reverse(char *string)
{
	int siz;
	char temp;
	static char tmpStr[SIZE_BIG];
	arrclean(tmpStr, SIZE_BIG);
	strcopy(tmpStr, string);

	for (siz = 0; tmpStr[siz] != '\0'; ++siz)
		;
	for (int h = 0, l = --siz; h != l && h != l + 1; ++h, --l)
	{
		temp = tmpStr[l];
		tmpStr[l] = tmpStr[h];
		tmpStr[h] = temp;
	}
	return tmpStr;
}