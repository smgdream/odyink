#include <stdio.h>
#include <stdarg.h>
#include "dcl.h"

#ifndef SIZEDEF_H
#define SIZEDEF_H 
#define SIZE_4K 4096
#define SIZE_BIG 1024
#define SIZE_MED 256
#define SIZE_SML 32

#endif

char *cat(const char *fmt, ...)
{
	static char s[SIZE_4K + 1];
	va_list args;
	
	va_start(args, fmt);
	vsprintf(s, fmt, args);
	va_end(args);
	return s;
}