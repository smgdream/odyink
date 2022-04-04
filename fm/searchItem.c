#include <stdio.h>
#include <string.h>
#include "../include/format.h"

int search(char *keyword)
{
	int found = 0;
	char tmpIndex[INDEX_LEN + 1];
	FILE *fp;
	fp = fopen("./odydata/docindex.ini", "r");
	while (fgets(tmpIndex, INDEX_LEN + 1, fp) != NULL)
	{
		for (int i = 0; i < INDEX_LEN; ++i)
			if (tmpIndex[i] == '\v' || tmpIndex[i] == '\t')
				tmpIndex[i] = '\0';
		if (strstr(tmpIndex, keyword) != NULL)
		{
			printf("%s\n", tmpIndex);
			++found;
		}
	}
	return found;
}