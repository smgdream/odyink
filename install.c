#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/def.h"

void install(void)
{
	// Install Odyink Client
	printf("Enter to start installation\n");
	getchr();
	clear();
	printf("Instailling Odyink Client...\n");
	// Make dir odydata
	if (OSNUM)
		system("mkdir odydata\\doc nul 2> nul");
	else
		system("mkdir -p odydata/doc");

	printf("website:");
	writeUrl();
	printf("\nFinish\n");
	genSleep(2);
	clear();
	return;
}