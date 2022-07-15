#include <stdio.h>
#include "dcl.h"

#ifndef SIZEDEF_H
#define SIZEDEF_H 
#define SIZE_4K 4096
#define SIZE_BIG 1024
#define SIZE_MED 256
#define SIZE_SML 32

#endif

char getchr(void)
{
	int i = 0;
	char ch = '\0';
	char tc = '\0';

	while ((tc = fgetc(stdin)) != '\n' && tc != EOF)
		if (i++ == 0)
			ch = tc;
	return ch;
}

char *getstr(char *s, int n)
{
	char tmpstr[SIZE_BIG + 1];
	
	file_getline(tmpstr, sizeof tmpstr, stdin);
	for (char *sptr = s, *tptr = tmpstr; (*sptr++ = *tptr++) && *sptr != '\n' && --n;)
		;
	return s;
}


char *file_getline(char *s, int n, FILE *stream)
{
	char *tmps = s;

	for (; (*tmps = fgetc(stream)) && *tmps != '\n' && *tmps != EOF && --n; ++tmps)
		;
	*tmps = '\0';
	return s;
}
