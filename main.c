/*
 * odyink server: A Document manager
 * Author: smgdream
 * Version: 0.6.1b
 * Modify date: 2022-07-15 (UTC+8)
 */

#include <stdlib.h>
#include "dcl.h"

Odyconf *oconf = NULL;

static void init_ody();
static void clean_ody();


int main(void)
{
	clear();
	if (OSTYPE)
		cmd_init();
	if (!fexist(CONFIG_PATH"/ody_path.ini"))
		install_ody();
	init_ody();

	doc_index();

	clean_ody();
	return 0;
}


static void init_ody(void)
{
	oconf = ocfg_create();

	ocfg_set_path(oconf,CONFIG_PATH"/ody_path.ini");
	ocfg_set_headptr(oconf, lap_load_data(ocfg_data_file(oconf)) );

	clear();
	return;
}


static void clean_ody(void)
{
	lap_save_data(ocfg_headptr(oconf), ocfg_data_file(oconf));
	lap_close_data(ocfg_headptr(oconf));
	
	if (OSTYPE)
		cmd_restore();
	clear();
	return;
}
