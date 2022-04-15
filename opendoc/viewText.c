#include <stdio.h>
#include "../include/def.h"

int getcUTF8(char *bl1, FILE *fp);

void viewText(char *fpath)
{
	char bufL1[5];
	int sign = 0;
	FILE *fp = NULL;
	fp = fopen(fpath, "r");

	while ((sign = getcUTF8(bufL1, fp))) {
		fwrite(bufL1, 5, 1, stdout);
		if (sign == EOF)
			break;
	}
	fclose(fp);
}