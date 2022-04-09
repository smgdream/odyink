#include <stdio.h>
#include <ctype.h>
#include "./include/def.h"
#include "./include/format.h"

#define NODATA (EOF)

void renameDoc(void)
{
	while (1)
	{
		char newtitle[TITLE_MAX_LEN + 1];
		char idstr[12];
		char newindex[INDEX_LEN + 1];
		int id = NODATA;
		clear();

		viewIndex("./odydata/docindex.ini");
		printf("\n[Q]uit\n\n");
		printf("ID: ");
		getstr(idstr, 12);
		if (toupper(idstr[0]) == 'Q')
			continue;
		if ((id = stoi(idstr)) == NODATA) {
			printf("Input Error\n");
			genSleep(2);
			continue;
		}
		
		printf("newtitle:");
		getstr(newtitle, TITLE_MAX_LEN);

		sprintf(newindex, "%s.%s", itos(id), newtitle);
		sprintf(newindex, "%s\t", fill(newindex, -(INDEX_LEN - 1), '\v'));
		indexCov(id, newindex);
		continue;
	}
	return;
}