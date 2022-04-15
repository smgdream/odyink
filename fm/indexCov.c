#include <stdio.h>
#include "../include/format.h"

void indexCov(int docId, char *index)
{
	FILE *fp = NULL;
	fp = fopen("./odydata/docindex.ini", "r+");
	if (fp == NULL)
		return;
	// Please view the Dev Document
	fseek(fp, INDEX_LEN * docId, SEEK_SET);
	fputs(index, fp);
	fclose(fp);
	return;
}