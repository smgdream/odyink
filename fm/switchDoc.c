#include <stdio.h>
#include "../include/format.h"


int backDoc(int id)
{
	int c = 0;
	int nowid = id;
	if (nowid < 1)
		return nowid;
	FILE *fp;
	fp = fopen("./odydata/doctype.ini", "r");
	while (!fseek(fp, --id * TYPE_LEN + TYPE_OFFSET, SEEK_SET))
		if ((c = fgetc(fp)) != 'n')
		{
			fclose(fp);
			return id;
		}
	fclose(fp);
	return nowid;
}

int nextDoc(int id)
{
	int c = 0;
	int nowid = id;
	if (nowid > ID_MAX - 1)
		return nowid;
	FILE *fp;
	fp = fopen("./odydata/doctype.ini", "r");
	while (!fseek(fp, ++id * TYPE_LEN + TYPE_OFFSET, SEEK_SET))
		if ((c = fgetc(fp)) != 'n')
		{
			if (c == EOF)
				break;
			fclose(fp);
			return id;
		}
	fclose(fp);
	return nowid;
}