#include <stdio.h>
#include <stdlib.h>

#define SIZE_BIG 1024

void runPy(const char *fpath)
{
	char tmpstr[SIZE_BIG];
	sprintf(tmpstr, "python %s", fpath);
	system(tmpstr);
}