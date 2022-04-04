#include <stdio.h>
#include <string.h>
#include "../include/def.h"

char *getType(char *fpath)
{
	char *start = NULL;
	static char type[5];
	arrclean(type, 5);

	start = strrchr(fpath, '.');
	sprintf(type, "%s", start);
	return type + 1;
}