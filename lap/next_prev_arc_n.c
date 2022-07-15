#include <stddef.h>
#include <stdint.h>
#include "lap_base.h"
#include "lap_ext.h"

/* 
 * 
 */
Laparc *lap_next_arc_n(void *headptr, Laparc *ptr, uint32_t num)
{
	Laparc *tmp = NULL;
	lap_arc_for_from_n(tmp, headptr, ptr, num)
		;
	return tmp;
}

/* 
 * 
 */
Laparc *lap_prev_arc_n(void *headptr, Laparc *ptr, uint32_t num)
{
	Laparc *tmp = NULL;
	lap_arc_for_from_prev_n(tmp, headptr, ptr, num)
		;
	return tmp;
}