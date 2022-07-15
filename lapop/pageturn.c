#include <stdio.h>
#include "lap.h"
#include "dcl.h"

Laparc *nextpage(void *headptr, Laparc *ptr, int lines)
{
	Laparc *raw = ptr;
	Laparc *tmp = NULL;

	ptr = lap_prev_arc_n(headptr, ptr, lines);
	if (ptr == NULL) {
		lap_arc_for_from_prev_n(tmp, headptr, raw, lines) // raw
			printf("%u.%s\n", lap_get_id(tmp), lap_get_title(tmp));
		return raw;
	}

	lap_arc_for_from_prev_n(tmp, headptr, ptr, lines)
		printf("%u.%s\n", lap_get_id(tmp), lap_get_title(tmp));
	return ptr;
}

Laparc *prevpage(void *headptr, Laparc *ptr, int lines)
{
	Laparc *raw = ptr;
	Laparc *tmp = NULL;

	ptr = lap_next_arc_n(headptr, ptr, lines);
	if (ptr == NULL) {
		lap_arc_for_from_prev_n(tmp, headptr, raw, lines) // raw
			printf("%u.%s\n", lap_get_id(tmp), lap_get_title(tmp));
		return raw;
	}
	
	lap_arc_for_from_prev_n(tmp, headptr, ptr, lines)
		printf("%u.%s\n", lap_get_id(tmp), lap_get_title(tmp));
	return ptr;
}

Laparc *thispage(void *headptr, Laparc *ptr, int lines)
{
	Laparc *tmp = NULL;
	lap_arc_for_from_prev_n(tmp, headptr, ptr, lines)
		printf("%u.%s\n", lap_get_id(tmp), lap_get_title(tmp));
	return ptr;
}
