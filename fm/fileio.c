#include <stdio.h>


int fexist(char *fpath)
{
	FILE *fp = NULL;

	if ((fp = fopen(fpath, "r")) == NULL)
		return 0;
	else
		fclose(fp);
	return 1;
}


void fnewout(char *fpath, char *text)
{
	FILE *fp = NULL;

	fp = fopen(fpath, "w+");
	fputs(text, fp);
	fclose(fp);
	return;
}


void faddout(char *fpath, char *text)
{
	FILE *fp = NULL;
	fp = fopen(fpath, "a+");

	fputs(text, fp);
	fclose(fp);
	return;
}


void fcopy(char *source, char *target)
{
	char tfs; // Temp file stream
	//
	FILE *fpSource;
	fpSource = fopen(source, "rb");
	//
	FILE *fpTarget;
	fpTarget = fopen(target, "wb+");
	// if use the feof() it will write the last byte again
	while (fread(&tfs, 1, 1, fpSource))
		fwrite(&tfs, 1, 1, fpTarget);
	//printf("Finish\n");
	//
	fclose(fpTarget);
	fclose(fpSource);
	return;
}


int fgeti(char *fpath)
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