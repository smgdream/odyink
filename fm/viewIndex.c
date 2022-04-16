#include <stdio.h>

void viewIndex(char *fpath)
{
	signed char ch = '\0';
	FILE *fp = NULL;
	fp = fopen(fpath, "r");
	if (fp == NULL)
		return;
	// Please viev the Dev Document
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '\v')
			continue;
		if (ch == '\t')
		{
			printf("\n");
			continue;
		}
		printf("%c", ch);
	}
	fclose(fp);
	return;
}