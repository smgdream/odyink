#include <stdio.h>
#include <stdlib.h>
#include "../include/def.h"

#if OSNUM
	#include <windows.h>
#else 
	#include <unistd.h>
#endif


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