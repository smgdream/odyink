#include "lap_base.h"
#include "chain.h"


int lap_close_data(void *headptr)
{
	lap_chain_remove(headptr);
	return 0;
}