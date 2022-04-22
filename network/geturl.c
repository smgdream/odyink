#include <stdio.h>

#define SIZE_MED 256

const char *getUrl(const char *fpath)
{
    static char tmpstr[SIZE_MED];
    FILE *fp = NULL;
    fp = fopen(fpath, "r");

    fgets(tmpstr, SIZE_MED, fp);
    if (fp != NULL)
        fclose(fp);
    return tmpstr;
}