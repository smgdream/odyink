#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "lap_base.h"
#include "laparc.h"
#include "inside_dcl.h"


/* 
 * 
 */
int lap_arc_remove(Laparc *ptr, const char *dir)
{
	if (ptr == NULL)
		return -1;

	if (strcmp(ptr->type, "nofile"))
		remove(lap__cat("%s/%u.%s", dir, ptr->id, ptr->type));

	lap_blk_remove(lap_get_lapblk(data, ptr));
	return 0;
}