#include <stdlib.h>
#include "ostype.h"

void runSh(const char *fpath)
{
	if (OSTYPE != WINDOWS)
		return;
	system(fpath);
	return;
}