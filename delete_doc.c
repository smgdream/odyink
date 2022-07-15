#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "sizedef.h"


static int del_data(unsigned int id);


void delete_doc(void)
{
	while (1)
	{
		char idstr[ID_LEN + 1];
		
		clear();
		index_print(ocfg_headptr(oconf));

		printf("\n[Q] return to the index\n\n");

		printf("DocID:");
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

		printf("Sure to delete [Y/n]:");
		if (toupper(getchr()) != 'Y')
			continue;
		
		if (del_data(stoi(idstr))) {
			continue;
		}
		printf("\nFinish\n");

		gen_sleep(2);
	}
	return;
}

static int del_data(unsigned int id)
{
	Laparc *ptr = lap_arc_get(ocfg_headptr(oconf), id);
	if (ptr == NULL) {
		printerr("don't exist document id:%u\n", id);
		gen_sleep(3);
		clear();
		return 1;
	}

	lap_arc_remove(ptr, ocfg_doc(oconf));
	logger(cat("%s+08:00\tDelete: %u\n", timestr(UTC), id ));
	return 0;
}