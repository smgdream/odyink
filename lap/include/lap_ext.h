#ifndef LAP_EXT_H
#define LAP_EXT_H

#include <stdint.h>
#include "lap_base.h"


/* 
 * 
 */
#define lap_arc_for_each(iter, headptr) \
	for (iter = lap_first_arc(headptr);\
		iter != NULL; \
		iter = lap_next_arc(headptr, iter))

/* 
 * 
 */
#define lap_arc_for_each_prev(iter, headptr) \
	for (iter = lap_last_arc(headptr); \
		iter != NULL; \
		iter = lap_prev_arc(headptr, iter))

/* 
 * 
 */
#define lap_arc_for_from_n(iter, headptr, beg, cnt) \
	for (uint32_t _iter_cnt = cnt; _iter_cnt; _iter_cnt = 0) \
		for (iter = beg;\
			_iter_cnt-- && iter != NULL; \
			iter = lap_next_arc(headptr, iter))

/* 
 * 
 */
#define lap_arc_for_from_prev_n(iter, headptr, beg, cnt) \
	for (uint32_t _iter_cnt = cnt; _iter_cnt; _iter_cnt = 0) \
		for (iter = beg;\
			_iter_cnt-- && iter != NULL; \
			iter = lap_prev_arc(headptr, iter))

/* 
 * 
 */
Laparc *lap_next_arc_n(void *headptr, Laparc *ptr, uint32_t num);

/* 
 * 
 */
Laparc *lap_prev_arc_n(void *headptr, Laparc *ptr, uint32_t num);


/* 
 * 
 */
static inline int lap_arc_is_empty(void *headptr)
{
	return (lap_first_arc(headptr) == NULL);
}


#endif