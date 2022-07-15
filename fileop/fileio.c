#include <stdio.h>
#include "dcl.h"


int fexist(const char *fpath)
{
	FILE *fp = fopen(fpath, "r");

	if (fp) {
		fclose(fp);
		return 1;
	}
	else
		return 0;
}

int filecreate(const char *fpath, char flag)
{
	FILE *fp = fopen(fpath, (flag == 'b') ? "wb" : "w");
	
	return ( (fp) ? fclose(fp) : EOF );
}

int fnewout(const char *fpath, const char *text)
{
	FILE *fp = fopen(fpath, "w");

	if (fp) {
		fputs(text, fp);
		fclose(fp);
		return 0;
	}
	return 1;
}


int faddout(const char *fpath, const char *text)
{
	FILE *fp = fopen(fpath, "a");

	if (fp) {
		fputs(text, fp);
		fclose(fp);
		return 0;
	}
	return 1;
}


int fcopy(const char *source, const char *target)
{
	typedef unsigned char Byte;
	Byte tfs; // Temp file stream
	
	FILE *fp_src = fopen(source, "rb");
	FILE *fp_dest = fopen(target, "wb");

	// if use the feof() it will write the last byte again
	while (fread(&tfs, sizeof(Byte), 1, fp_src))
		fwrite(&tfs, sizeof(Byte), 1, fp_dest);

	fclose(fp_dest);
	fclose(fp_src);

	return 0;
}


int fgeti(const char *fpath)
{
	int i;
	int number = 0;
	signed char strnum[12];
	FILE *fp = NULL;
	fp = fopen(fpath, "r");
	if (fp == NULL)
		return 0;

	// Please view the Dev Document
	/* Expr2 will set last element = EOF
	So I should deal with it*/
	for (i = 0; (strnum[i] = fgetc(fp)) != EOF; ++i)
		;
	strnum[i] = '\0';
	fclose(fp);
	for (i = 0; strnum[i] >= '0' && strnum[i] <= '9'; i++)
		number = 10 * number + (strnum[i] - '0');
	return number;
}