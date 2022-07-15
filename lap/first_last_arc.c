#include <stddef.h>
#include "lap_base.h"
#include "chain.h"


/* 
 * 
 */
Laparc *lap_first_arc(void *headptr)
{
	return (!lap_chain_empty(headptr)) ?
		( &(lap_get_lapblk(node, lap_to_nodeptr(headptr)->nextp)->data) )
		: NULL;
}

/* 
 * 
 */
Laparc *lap_last_arc(void *headptr)
{
	return (!lap_chain_empty(headptr)) ?
		( &(lap_get_lapblk(node, lap_to_nodeptr(headptr)->prevp)->data ) )
		: NULL;
}