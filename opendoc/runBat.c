#include <stdlib.h>

void runBat(const char *fpath)
{
	system("chcp 936 >nul");
	system(fpath);
	system("title Odyink Server");
	system("chcp 65001 >nul");
	system("color 07");
	return;
}