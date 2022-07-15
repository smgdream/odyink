#include <stdio.h>
#include "lap_base.h"
#include "chain.h"


/* 
 * 
 */
int lap_save_data(void *headptr, const char *datapath)
{
	FILE *fp = fopen(datapath, "wb");
	Lapblk *tmp = NULL;

	if (fp == NULL)
		return 1;

	lap_chain_for_each(tmp, headptr)
		fwrite(&tmp->data, sizeof(Laparc), 1, fp);

	fclose(fp);

	return 0;
}