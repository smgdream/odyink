#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "lap.h"

uint32_t index_print(void *headptr)
{
	uint32_t cnt = 0;

	Laparc *tmp = NULL;
	lap_arc_for_each(tmp, headptr) {
		printf("%u.%s\n", lap_get_id(tmp), lap_get_title(tmp));
		++cnt;
	}
	return cnt;
}

uint32_t index_find(void *headptr, const char *keyword)
{
	uint32_t cnt = 0;

	Laparc *tmp = NULL;
	lap_arc_for_each(tmp, headptr) {
		if (strstr(lap_get_title(tmp), keyword)) {
			printf("%u.%s\n", lap_get_id(tmp), lap_get_title(tmp));
			++cnt;
		}
	}
	return cnt;
}