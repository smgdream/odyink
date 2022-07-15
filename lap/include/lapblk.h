#ifndef LAPBLK_H
#define LAPBLK_H

#include "lap_types.h"
#include "list.h"


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
 * define Lapblk *lap_get_lapblk(menber, nodeptr)
 */
#define lap_get_lapblk(menber, nodeptr) \
	( list_entry(Lapblk, menber, nodeptr) )

/* 
 * 
 */
static inline Lapblk *lap_blk_create(void)
{
	return (Lapblk *)malloc(sizeof(Lapblk));
}

/* 
 * 
 */
static inline void lap_blk_insert(Lapblk *ptr, Lapblk *pos)
{
	node_insert(&(ptr)->node, &(pos)->node);
}

/* 
 * 
 */
static inline void lap_blk_add(void *headptr, Lapblk *ptr)
{
	node_insert(lap_to_nodeptr(headptr), &(ptr)->node);
}

/* 
 * 
 */
static inline void lap_blk_remove(Lapblk *ptr)
{
	list_entry_remove(&(ptr)->node, (void *)(ptr));
}

#endif