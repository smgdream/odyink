#include "dcl.h"

void logger(const char *log)
{
	faddout(ocfg_log(oconf), log);
	return;
}