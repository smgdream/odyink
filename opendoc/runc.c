#include <stdio.h>
#include <stdlib.h>
#include "ostype.h"

#define SIZE_BIG 1024

void runC(const char *fpath)
{
	char tmpstr[SIZE_BIG];
	sprintf(tmpstr, "gcc %s", fpath);
	system(tmpstr);
	if (OSTYPE) {
		system("a.exe");
		remove("a.exe");
	}
	else {
		system("./a.out");
		remove("a.exe");
	}
	return;
}