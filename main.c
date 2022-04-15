#include "include/def.h"

//#include "include/debug.h"

// Odyink Server
// version 0.5
// 2022-04-15 23:03:00 (UTC+8)

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
