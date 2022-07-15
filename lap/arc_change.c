#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "lap_base.h"
#include "lap_def.h"
#include "laparc.h"
#include "inside_dcl.h"


/* 
 * 
 */
int lap_arc_change(Laparc *ptr, const char *type, const char *title
					, const char *src, const char *dest)
{
	if (ptr == NULL)
		return -1;

	if (type != NULL) {
		if (!strcmp(type, "nofile")) {
			if (dest == NULL)
				return 1;
			remove(lap__cat("%s/%u.%s", dest, ptr->id, ptr->type));
		}
		if (strcmp(type, "nofile") 
		 && src != NULL
		 && dest != NULL) {
			if (strstr(src, type) == NULL
			 || !lap__fexist(src)
			 || lap__fcopy(src, lap__cat("%s/%u.%s", dest, ptr->id, type)))
				return 1;
		}
	}

	lap_arc_set(ptr, LAP_NOID, type, title);

	return 0;
}