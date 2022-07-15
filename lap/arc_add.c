#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "lap_base.h"
#include "laparc.h"
#include "lap_def.h"
#include "inside_dcl.h"


/* 
 * 
 */
int lap_arc_add(void *headptr, const char* type, const char *title
				, const char *src, const char *dest)
{
	Lapblk *newblk = NULL;
	uint32_t id = LAP_NOID;
	
	if (headptr == NULL)
		return -1;
	if (type == NULL || title == NULL)
		return 1;

	id = lap_newid(headptr);

	if (strcmp(type, "nofile")) {
		if (src == NULL
		 || dest == NULL
		 || !lap__fexist(src)
		 || lap__fcopy(src, lap__cat("%s/%u.%s", dest, id, type)))
			return 1;
	}
	
	newblk = lap_blk_create();
	lap_arc_set(&newblk->data, id, type, title);
	lap_blk_add(headptr, newblk);

	return 0;
}