#include <stdio.h>
#include <stdlib.h>
#include "../include/ostype.h"

#define SIZE_BIG 1024

void runCpp(const char *fpath)
{
	char tmpstr[SIZE_BIG];
	sprintf(tmpstr, "g++ %s", fpath);
	system(tmpstr);
	if (OSNUM) {
		system("a.exe");
		remove("a.exe");
	}
	else {
		system("./a.out");
		remove("a.exe");
	}
}