#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "format.h"

const char *get_filetype(const char *path)
{
	static char type[TYPE_LEN + 1];
	const char *beg = strrchr(path, '.') + 1,  *end = beg;
	unsigned int cnt = 0;
	
	for (;isalnum(*end++) && cnt < TYPE_LEN; ++cnt)
		;
	strncpy(type, beg, cnt);
	type[cnt] = '\0';
	return type;
}