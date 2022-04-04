#include <string.h>
#include "../include/def.h"

#define SIZE_BIG 1024

char *fill(char *string, int size, char ch)
{
	int si = 0; // String index
	int ti = 0; // tmpStr index
	int fillSign = 0;
	int strSiz = strlen(string);
	static char tmpStr[256];
	arrclean(tmpStr, 256);

	// Compute fillsize absolute & set fill sign
	fillSign = 1;
	if (size < 0)
	{
		size *= -1;
		fillSign = -1;
	}

	if (size < strSiz)
		return NULL;
	if (size == strSiz)
		return string;
	size -= strSiz;	// If filStr > strSiz

	// Low fill (fillSign == 1)
	if (fillSign == 1)
		for (ti = 0; size + strSiz > 0; ++ti)
		{
			if (size > 0)
			{
				tmpStr[ti] = ch;
				--size;
				continue;
			}
			if (size == 0 && strSiz > 0)
			{
				tmpStr[ti] = string[si++];
				--strSiz;
			}
		}
	// High fill (fillSign == -1)
	if (fillSign == -1)
		for (ti = 0; size + strSiz > 0; ++ti)
		{
			if (strSiz > 0)
			{
				tmpStr[ti] = string[si++];
				--strSiz;
				continue;
			}
			if (strSiz == 0 && size > 0)
			{
				tmpStr[ti] = ch;
				--size;
			}
		}
	tmpStr[ti] = '\0';
	return tmpStr;
}