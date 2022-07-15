#include <stdio.h>
#include <time.h>
#include "dcl.h"

#ifndef SIZEDEF_H
#define SIZEDEF_H 
#define SIZE_4K 4096
#define SIZE_BIG 1024
#define SIZE_MED 256
#define SIZE_SML 32

#endif

/* zone时区 */
const char *timestr(int zone)
{
	time_t tsp; // timestamp
	struct tm *timep; // timePointer
	static char tstr[SIZE_SML + 1]; // timestr
	arrclean(tstr, SIZE_SML + 1);
	
	time(&tsp);
	tsp += 3600 * zone;
	timep = gmtime(&tsp);
	strftime(tstr, SIZE_SML, "%Y-%m-%dT%H:%M:%S", timep);
	return tstr;
}