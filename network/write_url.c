#include <string.h>
#include "../include/def.h"

#define SIZE_MED 256

void writeUrl(void)
{
    unsigned int urlLen = 0;
	char url[SIZE_MED];
	arrclean(url, SIZE_MED);

    getstr(url, SIZE_MED);
	urlLen = strlen(url);
	if (urlLen == 0) {
		strcpy(url, "https://ody.ink/odydata");
		urlLen = strlen(url);
	}
	if (url[urlLen - 1] == '/')
		url[urlLen - 1] = '\0';
	fnewout("./odydata/website.ini", url);
    return;
}