#include <stdio.h>
#include "../include/def.h"

void cleanData(void)
{
	if (fexist("./odydata/docindex.ini"))
		remove("./odydata/docindex.ini");
	if (fexist("./odydata/doctype.ini"))
		remove("./odydata/doctype.ini");
	if (fexist("./odydata/docnum.ini"))
		remove("./odydata/docnum.ini");
	return;
}