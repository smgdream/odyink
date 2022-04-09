#include "include/def.h"

//#include "include/debug.h"

// version 0.5 Dev
// 2022-04-09 23:55:30 (UTC+8)

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
