#include <stdio.h>
#include <stdlib.h>

int webGet(const char *url, const char *savePath)
{
    char tmpstr[600];
	int ret = 0;

    sprintf(tmpstr, "wget -q -t 3 -P %s \"%s\"", savePath, url);
	ret = system(tmpstr);
	if (ret)
		fprintf(stderr, "Error:webGet() : Network connection error!\n"
						"\tURL: %s\n", tmpstr);
    return ret;
}