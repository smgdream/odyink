
#ifndef LAP_ARC_H
#define LAP_ARC_H

#include "lap_types.h"
#include "chain.h"

/* 
 * 
 */
int lap_arc_set(Laparc *ptr, uint32_t id
	, const char *type, const char *title);

/* 
 * 
 */
static inline uint32_t lap_newid(void *headptr)
{
	return (!lap_chain_empty(headptr)) ?
		(lap_get_lapblk(node, lap_to_nodeptr(headptr)->prevp)->data.id + 1)
		: ((uint32_t)0);
}


#endif
// #include "laparc/laparc.h"