#include <stdio.h>
#include "../include/def.h"
#include "../include/format.h"


char *readType(int docId)
{
	static char type[4];
	arrclean(type, 4);
	FILE *fp = NULL;
	fp = fopen("./odydata/doctype.ini", "r");
	if (fp == NULL)
		return NULL;
	// Please view the Dev Document
	fseek(fp, TYPE_LEN * docId + TYPE_OFFSET, SEEK_SET);
	fgets(type, 3 + 1, fp);
	for (int i = 0; i < 3; ++i)
		type[i] == '0' ? type[i] = '\0' : 0 ;
	fclose(fp);
	return type;
}
