#include <stdio.h>
#include <time.h>
#include "../include/def.h"

#define SIZE_SML 32

/* zone时区 */
char *timeStr(int zone)
{
	time_t tsp; // timestamp
	struct tm *timep; // timePointer
	static char tstr[SIZE_SML]; // timestr
	arrclean(tstr, SIZE_SML);
	
	time(&tsp);
	tsp += 3600 * zone;
	timep = gmtime(&tsp);
	strftime(tstr, SIZE_SML, "%Y-%m-%d %H:%M:%S", timep);
	return tstr;
}