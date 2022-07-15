#include <stdio.h>
#include <string.h>
#include "marg_tree_type.h"
#include "dcl.h"

Marg_tree _matree;
Marg_tree *matree = &_matree;


int args_parser(char *margv[])
{
	for (char *arg = *margv; arg != NULL; ++arg) {
		if (arg == margv) {
			strcpy(matree.pgm_name, arg);
			break;
		}
		if (!strcmp(arg, "--src")) {
			if (*(arg + 1) != '-') {
				matree.datasrc_flag = 1;
				strcpy(marg_tree.datasrc, ++arg);
				break;
			}
		}
		printerr("wrong: undefine command line argument:\"%s\"", arg);
	}
}