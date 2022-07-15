#include <string.h>
#include <ctype.h>
#include "dcl.h"

char *fmt_path(char *path)
{
	char *beg = path, *end = path + strlen(path);
	
	for (; isspace(*beg) || *beg == '\'' || *beg == '\"'; ++beg)
		;
	for (--end; isspace(*end) || *end == '\'' || *end == '\"'; --end)
		;
	*(end + 1) = '\0';
	return beg;
}