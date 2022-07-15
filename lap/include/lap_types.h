#ifndef LAP_TYPES_H
#define LAP_TYPES_H


#include <stdint.h>
#include "lap_format.h"


struct list_head {
	struct list_head *nextp, *prevp;
};

struct laparc {
	uint32_t id;
	char type[LAP_TYPE_LEN + 1];
	char title[LAP_TITLE_MAX_LEN + 1];
};
typedef struct laparc Laparc;

struct lapblock {
	struct list_head node;
	Laparc data;
};
typedef struct lapblock Lapblk;


#endif