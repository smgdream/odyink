#include <stdio.h>
#include <stdlib.h>
#include "include/def.h"
#include "include/format.h"

#define SIZE_MED 256

void install(void)
{
	char index[INDEX_LEN];
	char logs[SIZE_MED];

	// Install Odyink Server
	printf("Enter to start installation\n");
	getchr();
	printf("Instailling Odyink Server...\n");
	// Make dir odydata
	if (OSNUM)
		system("mkdir odydata\\doc nul 2> nul");
	else
		system("mkdir -p odydata/doc");
	fnewout("./odydata/docnum.ini", "1");
	fnewout("./odydata/allocid.ini", "0");
	sprintf(index, "%s%c", fill("0.Hello Odyink", -(INDEX_LEN -1), '\v'), '\t');
	fnewout("./odydata/docindex.ini", index);
	// It have a space after type
	fnewout("./odydata/doctype.ini", "0000000 txt\t");
	fnewout("./odydata/doc/0.txt", "Hello this is Odyink\n");
	faddout("./odydata/doc/0.txt", "\n");
	faddout("./odydata/doc/0.txt", "Odyink is make by smgdream & Andyccr\n");
	sprintf(logs, "%s (UTC)\t %s\n", timeStr(UTC), "Install Odyink Server");
	fnewout("./odydata/odyink.log", logs);
	printf("\nFinish\n");
	genSleep(2);
	return;
}