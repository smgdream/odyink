#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"


static int write_data(const char *path, const char *title);


void import_doc(void)
{
	while (1)
	{
		char file_path[SIZE_MED + 1];
		char doc_title[TITLE_MAX_LEN + 1];

		clear();
		// Input file path
		printf("[Q] return to the index\n");
		printf("\n");

		printf("Doc path:");
		getstr(file_path, 256);
		strcpy( file_path, fmt_path(to_unixpath(file_path)) );

		if (!strcmp(file_path, "q") || !strcmp(file_path, "Q"))
			return;
		if (!fexist(file_path))
		{
			printf("File does not exist\n");
			gen_sleep(3);
			continue;
		}

		// Input Doc title
		printf("Doc title:");
		getstr(doc_title, TITLE_MAX_LEN); // Don't change easy
		if (!strcmp(doc_title, "q") || !strcmp(doc_title, "Q"))
			return;

		write_data(file_path, doc_title);
		printf("\nFinish\n");

		gen_sleep(2);
		clear();
	}
}


static int write_data(const char *path, const char *title)
{
	lap_arc_add(ocfg_headptr(oconf), get_filetype(path), title
		, path, ocfg_doc(oconf));

	logger(cat("%s+08:00\tImport: %u %s\n", timestr(UTC)
		, lap_get_id( lap_last_arc(ocfg_headptr(oconf)) )
		, lap_get_type( lap_last_arc(ocfg_headptr(oconf)) ) 
		));
	return 0;
}
