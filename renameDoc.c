#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "./include/def.h"
#include "./include/format.h"

#define NODATA (EOF)

void renameDoc(void)
{
	while (1)
	{
		char newTitle[TITLE_MAX_LEN + 1];
		char idstr[12];
		char newIndex[INDEX_LEN + 1];
		int id = NODATA;
		clear();

		viewIndex("./odydata/docindex.ini");
		printf("\n[Q]uit\n\n");

		printf("ID: ");
		getstr(idstr, 12);
		if (!strcmp(idstr, "q") || !strcmp(idstr, "Q"))
			break;
		if ((id = stoi(idstr)) == NODATA) {
			printf("Input Error\n");
			genSleep(2);
			continue;
		}
		
		printf("newTitle:");
		getstr(newTitle, TITLE_MAX_LEN);
		if (!strcmp(newTitle, "q") || !strcmp(newTitle, "Q"))
			break;

		sprintf(newIndex, "%s.%s", itos(id), newTitle);
		sprintf(newIndex, "%s\t", fill(newIndex, -(INDEX_LEN - 1), '\v'));
		indexCov(id, newIndex);
		continue;
	}
	return;
}