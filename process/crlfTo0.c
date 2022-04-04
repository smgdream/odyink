#include <string.h>
#include "../include/def.h"

#define SIZE_BIG 1024

char *crlfto0(char *string)
{
	static char tmpStr[SIZE_BIG];
	arrclean(tmpStr, SIZE_BIG);
	strcpy(tmpStr,string);
	for (int i = 0;tmpStr[i] != '\0';++i)
	{
		if (tmpStr[i] == '\r' || tmpStr[i] == '\n')
			tmpStr[i] = '\0';
	}
	return tmpStr;
}