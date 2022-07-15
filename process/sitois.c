#include <stdio.h>
#include <string.h>
#include "dcl.h"

#ifndef SIZEDEF_H
#define SIZEDEF_H 
#define SIZE_4K 4096
#define SIZE_BIG 1024
#define SIZE_MED 256
#define SIZE_SML 32

#endif


int stoi(const char *numstr)
{
	int number = EOF;
	sscanf(numstr, "%d", &number);
	return number;
}


char *itos(int number)
{
	static char numstr[12];
	sprintf(numstr, "%d", number);
	return numstr;
}