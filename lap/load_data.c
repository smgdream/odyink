#include <stdio.h>
#include "lap_base.h"
#include "chain.h"
#include "lapblk.h"


/* 
 * 
 */
void *lap_load_data(const char *datapath)
{
	FILE *fp = fopen(datapath, "rb");
	void *headptr = lap_chain_create();
	Lapblk *tmp = lap_blk_create();

	for (; fread(&tmp->data, sizeof(Laparc), 1, fp) == 1
	     ; tmp = lap_blk_create())
		lap_blk_add(headptr, tmp);

	fclose(fp);
	free(tmp); // The last allocated memory unused, So free it.

	return headptr;
}