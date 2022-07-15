#include <stddef.h>
#include "lap_base.h"
#include "chain.h"


/* 
 * 
 */
Laparc *lap_next_arc(void *headptr, Laparc *ptr)
{
	return (lap_get_lapblk(data, ptr)->node.nextp != (headptr)) ?
		(&(lap_get_lapblk(node, lap_get_lapblk(data, ptr)
									->node.nextp)->data))
		: NULL;
}

/* 
 * 
 */
Laparc *lap_prev_arc(void *headptr, Laparc *ptr)
{
	return (lap_get_lapblk(data, ptr)->node.prevp != (headptr)) ?
		(&(lap_get_lapblk(node, lap_get_lapblk(data, ptr)
									->node.prevp)->data))
		: NULL;
}