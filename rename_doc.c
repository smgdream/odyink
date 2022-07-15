#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "format.h"
#include "sizedef.h"

static int change_data(unsigned int id, const char *title);

void rename_doc(void)
{
	while (1)
	{
		char new_title[TITLE_MAX_LEN + 1];
		char idstr[ID_LEN + 1];

		clear();
		index_print(ocfg_headptr(oconf));
		printf("\n[Q]uit\n\n");

		printf("ID: ");
		getstr(idstr, ID_LEN + 1);

		if (!isdigit(*idstr)) {
			if (!strcmp(idstr, "q") || !strcmp(idstr, "Q"))
				return;
			else {
				printf("Input error\n");
				gen_sleep(2);
				continue;
			}
		}
		
		printf("new title:");
		getstr(new_title, TITLE_MAX_LEN);
		if (!strcmp(new_title, "q") || !strcmp(new_title, "Q"))
			break;

		if (change_data(stoi(idstr), new_title)) {
			continue;
		}
		printf("\nFinish\n");
		
		gen_sleep(2);
	}
	return;
}

static int change_data(unsigned int id, const char *title)
{
	Laparc *ptr = lap_arc_get(ocfg_headptr(oconf), id);
	if (ptr == NULL) {
		printerr("don't exist document id:%u\n", id);
		gen_sleep(3);
		clear();
		return 1;
	}

	lap_arc_change(ptr, NULL, title, NULL, NULL);

	logger(cat("%s+08:00\tRename: %u\n", timestr(UTC)
		, lap_get_id( lap_last_arc(ocfg_headptr(oconf)) )
		));

	return 0;
}
