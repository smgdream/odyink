#include <stdlib.h>
#include "ostype.h"

void runBat(const char *fpath)
{
	if (OSTYPE != WINDOWS)
		return;
	system("chcp 936 >nul");
	system(fpath);
	system("title Odyink Server");
	system("chcp 65001 >nul");
	system("color 07");
	return;
}