#include <stdio.h>
#include <stdlib.h>
#include "dcl.h"


void viewText(const char *fpath)
{
	char command[64];
	if (OSTYPE)
	{
		sprintf(command,"type %s",to_winpath(fpath));
		system(command);
	}
	else
	{
		printf("\n");
		sprintf(command,"cat %s",to_unixpath(fpath));
		system(command);
	}
	printf("\n");
	return;
}