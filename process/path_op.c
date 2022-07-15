#include <string.h>
#include "dcl.h"

#ifndef SIZEDEF_H
#define SIZEDEF_H 

#define SIZE_4K 4096
#define SIZE_BIG 1024
#define SIZE_MED 256
#define SIZE_SML 32

#endif


char *to_winpath(const char *fpath)
{
	static char tmpePath[SIZE_BIG];
	strcpy(tmpePath, fpath);

	for (int i = 0; tmpePath[i] != '\0'; ++i) {
		if (tmpePath[i] == '/')
			tmpePath[i] = '\\';
	}
	return tmpePath;
}


char *to_unixpath(const char *fpath)
{
	static char tmpePath[SIZE_BIG];
	strcpy(tmpePath,fpath);

	for (int i = 0; tmpePath[i] != '\0'; ++i) {
		if (tmpePath[i] == '\\')
			tmpePath[i] = '/';
	}
	return tmpePath;
}