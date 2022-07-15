#include <stdio.h>
#include <stdlib.h>
#include "dcl.h"

#if OSTYPE
	#include <windows.h>
#else 
	#include <unistd.h>
#endif

#ifndef SIZEDEF_H
#define SIZEDEF_H 
#define SIZE_4K 4096
#define SIZE_BIG 1024
#define SIZE_MED 256
#define SIZE_SML 32

#endif


void clear(void)
{
	if (OSTYPE)
		system("cls");
	else
		printf("\033c");
	return;
}

int mkdir(const char *dir)
{
	if (OSTYPE)
		return system(cat("mkdir %s nul 2> nul", to_winpath(dir)));
	else
		return system(cat("mkdir -p %s", to_unixpath(dir)));
}

#if OSTYPE
	void gen_sleep(int seconds)
	{
		Sleep(seconds * 1000);
		return;
	}
#else
	void gen_sleep(int seconds)
	{
		sleep(seconds);
		return;
	}
#endif

int edit_text(const char *fpath)
{
	if (OSTYPE)
		return system(cat("notepad.exe %s", fpath));
	else
		return system(cat("gedit %s", fpath));
}