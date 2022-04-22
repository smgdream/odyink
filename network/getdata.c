#include <stdio.h>
#include "../include/def.h"

int getData(const char *url)
{
    char tmpstr[300];

	cleanData();
    sprintf(tmpstr, "%s/%s", url, "docindex.ini");
    if (webGet(tmpstr, "./odydata/"))
        return 1;
    sprintf(tmpstr, "%s/%s", url, "doctype.ini");
    if (webGet(tmpstr, "./odydata/"))
        return 1;
    sprintf(tmpstr, "%s/%s", url, "docnum.ini");
    if (webGet(tmpstr, "./odydata/"))
        return 1;
    return 0;
}