#include <stdio.h>
#include "../include/def.h"

#define SIZE_MED 256

int getDoc(int id, const char *type)
{
	char tmpstr[SIZE_MED];
	
	sprintf(tmpstr, "%s/doc/%d.%s", getUrl("./odydata/website.ini"), id, type);
	return webGet(tmpstr, "./odydata/doc/");
}