#include <stdio.h>
#include "../include/def.h"

int getcUTF8(char *bl1, FILE *fp);

void viewText(char *fpath)
{
	char bufL1[5];
	FILE *fp = NULL;
	fp = fopen(fpath, "r");

	while (getcUTF8(bufL1, fp) != EOF)
		fwrite(bufL1, 5, 1, stdout);
	putchar('\n');
}