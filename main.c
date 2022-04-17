#include "include/def.h"

//#include "include/debug.h"

// Odyink Server
// v0.5-pre1
// 2022-04-17 (UTC+8)

int main()
{
	if (OSNUM)
		cmdInit();
	clear();

	if (!fexist("./odydata/odyink.log"))
		install();
	clear();

	docIndex();

	if (OSNUM)
		cmdRestore();
	clear();
	return 0;
}
