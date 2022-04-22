#include <stdio.h>
#include "../include/def.h"

void changeWebsite(void)
{
	clear();
	printf("website:");
	writeUrl();
	if (getData(getUrl("./odydata/website.ini"))) {
		clear();
		printf("Network error!\n");
		genSleep(2);
	}
	return;
}