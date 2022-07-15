#ifndef LAP_CHAIN_H
#define LAP_CHAIN_H

#include <stdint.h>
#include <stdlib.h>
#include "list.h"
#include "lapblk.h"


//
#ifndef LAP_TO_NOTEPTR
#define LAP_TO_NOTEPTR
/* 
 * 
 */
static inline struct list_head *lap_to_nodeptr(void *ptr)
{
	return (struct list_head *)(ptr);
}
#endif


/* 
 * 
 */
#define lap_chain_for_each(iter, headptr) \
	list_for_each_entry(iter, lap_to_nodeptr(headptr), Lapblk, node)

/* 
 * 
 */
#define lap_chain_for_each_prev(iter, headptr) \
	list_for_each_entry_prev(iter, lap_to_nodeptr(headptr), Lapblk, node)

/* 
 * 
 */
static inline void *lap_chain_create()
{
	return (void *)list_head_create();
}

/* 
 * 
 */
static inline void lap_chain_remove(void *headptr)
{
	Lapblk *tmpptr = NULL;
	lap_chain_for_each_prev(tmpptr, headptr)
		lap_blk_remove(tmpptr);
	node_remove(lap_to_nodeptr(headptr));
}

/* 
 * 
 */
static inline int lap_chain_empty(void *headptr)
{
	return list_empty(lap_to_nodeptr(headptr));
}

/* 
 * 
 */
uint32_t lap_chain_size(void *headptr);

#endif
