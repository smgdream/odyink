#include <stddef.h>
#include <stdint.h>
#include "chain.h"
#include "laparc.h"

/* 
 * 
 */
uint32_t lap_chain_size(void *headptr)
{
	uint32_t cnt = 0;
	struct list_head *tmpptr = NULL;

	list_for_each(tmpptr, lap_to_nodeptr(headptr))
		++cnt;
		
	return cnt;
}
