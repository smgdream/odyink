#include <stdlib.h>
#include "dcl.h"

void cmd_init(void)
{
	system("title Odyink Server");
	system("chcp 65001");
	return;
}


void cmd_restore(void)
{
	system("title cmd");
	system("chcp 936");
	return;
}