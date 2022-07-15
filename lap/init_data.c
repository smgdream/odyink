#include "lap_base.h"
#include "inside_dcl.h"


/* 
 * 
 */
int lap_init_data(const char *datafile)
{
	return lap__filecreate(datafile, 'b');
}