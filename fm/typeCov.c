#include <stdio.h>
#include "../include/format.h"

void typeCov(int docId, char *type)
{
	FILE *fp = NULL;
	fp = fopen("./odydata/doctype.ini", "r+");
	if (fp == NULL)
		return;
	// Please viev the Dev Document
	fseek(fp, TYPE_LEN * docId + TYPE_OFFSET, SEEK_SET);
	fputs(type, fp);
	fclose(fp);
	return;
}