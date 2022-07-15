#include <stdio.h>
#include <string.h>
#include "ocfg_type.h"
#include "dcl.h"


/* 
 * 
 */
Odyconf *ocfg_set_path(Odyconf *ptr, const char *cfg_file)
{
	char tmpstr[SIZE_BIG + 1];
	FILE *fp = fopen(cfg_file, "r");

	file_getline(tmpstr, sizeof tmpstr, fp);
	fclose(fp);
	strcpy(ptr->path.data_dir, tmpstr);
	strcpy(ptr->path.data_file, cat("%s/%s", tmpstr,"index.dat"));
	strcpy(ptr->path.doc, cat("%s/%s", tmpstr,"doc/"));
	strcpy(ptr->path.log, cat("%s/%s", tmpstr,"odyink.log"));

	return ptr;
}

/* 
 * 
 */
Odyconf *ocfg_set_headptr(Odyconf *ptr, void *headptr)
{
	ptr->headptr = headptr;
	return ptr;
}