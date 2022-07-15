#include <stdlib.h>
#include "dcl.h"

void reinstall(void)
{
	install_ody();

	lap_close_data(ocfg_headptr(oconf));
	ocfg_set_headptr( oconf, lap_load_data(ocfg_data_file(oconf)) );

	exit(0);
}