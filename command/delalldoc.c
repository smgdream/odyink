#include <stdio.h>
#include <stdlib.h>
#include "../include/ostype.h"

void delAllDoc(void)
{
	if (OSNUM)
	{
		system("del /f /q .\\odydata\\doc\\*");
		system("del /f /q .\\odydata\\doc");
		system("del /f /q .\\odydata\\*");
		system("del /f /q .\\odydata");
	}
	else
		system("rm ./odydata*");
	return;
}