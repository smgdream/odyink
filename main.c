#include <stdio.h>
#include "include/def.h"

//#include "include/debug.h"

// Odyink Client
// v0.5.0.1-Dev
// 2022-04-17 (UTC+8)

int main()
{
	if (OSNUM)
		cmdInit();
	clear();

	if (!fexist("./odydata/website.ini"))
		install();
	clear();

	printf("Getting data...\n");
	if (!getData(getUrl("./odydata/website.ini")))
		docIndex();
	else {
		clear();
		printf("Network error!\n");
		genSleep(2);
	}

	cleanData();
	if (OSNUM)
		cmdRestore();
	clear();
	return 0;
}
