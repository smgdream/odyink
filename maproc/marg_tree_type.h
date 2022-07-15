#ifndef MARG_TREE_TYPE
#define MARG_TREE_TYPE

#include "dcl.h"

struct marg_tree {
	int datasrc_flag;
	char prgname[SIZE_BIG + 1];
	char datasrc[SIZE_BIG + 1];
};

typedef struct marg_tree Marg_tree;

Marg_tree *matree;

#endif