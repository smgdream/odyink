#include "include/def.h"

//#include "include/debug.h"

// version 0.4
// 2022-01-25 21:50:30 (UTC+8)

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
