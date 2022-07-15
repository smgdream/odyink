#include <stdlib.h>
#include "lap_types.h"
#include "list.h"

/* 
 * 
 */
struct list_head *list_head_create()
{
	struct list_head *headNode = malloc(sizeof(struct list_head));
	if (headNode == NULL)
		return NULL;
	headNode->nextp = headNode;
	headNode->prevp = headNode;
	return headNode;
}
