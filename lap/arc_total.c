#include <stdint.h>
#include "chain.h"

uint32_t lap_arc_total(void *headptr)
{
	return lap_chain_size(headptr);
}