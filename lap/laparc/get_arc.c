#include <stddef.h>
#include <stdint.h>
#include "chain.h"
#include "laparc.h"

/* 
 * 
 */
Laparc *lap_arc_get(void *headptr, uint32_t id)
{
	Lapblk *tmpptr = NULL;
	
	lap_chain_for_each_prev(tmpptr, headptr) 
		if (tmpptr->data.id == id)
			return &tmpptr->data;
	return NULL;
}