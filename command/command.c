#include <stdio.h>
#include <stdlib.h>
#include "../include/def.h"

#if OSNUM
	#include <windows.h>
#else 
	#include <unistd.h>
#endif

#define SIZE_MED 256


void clear(void)
{
	if (OSNUM)
		system("cls");
	else
		printf("\033c");
	return;
}

#if OSNUM
	void genSleep(int second)
	{
		Sleep(second * 1000);
		return;
	}
#else
	void genSleep(int second)
	{
		sleep(second);
		return;
	}
#endif

void editText(const char *fpath)
{
	char tmpstr[SIZE_MED];
	
	if (OSNUM) {
		sprintf(tmpstr, "notepad.exe %s", fpath);
		system(tmpstr);
	}
	else {
		sprintf(tmpstr, "gedit %s", fpath);
		system(tmpstr);
	}
	return;
}