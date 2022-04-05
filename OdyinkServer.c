#include "include/def.h"

//#include "include/debug.h"

// version 0.5 Dev

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
