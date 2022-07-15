#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "lap_base.h"
#include "lap_def.h"
#include "laparc.h"

/* 
 * 
 */
int lap_arc_set(Laparc *ptr, uint32_t id
	, const char *type, const char *title)
{
	if (id != LAP_NOID)
		ptr->id = id;
	if (type != NULL)
		memmove(ptr->type, type, strlen(type) + 1);
	if (title != NULL)
		memmove(ptr->title, title, strlen(title) + 1);
		
	return 0;
}
