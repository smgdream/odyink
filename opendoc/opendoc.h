#ifndef OPENDOC_H
#define OPENDOC_H

#include "lap.h"

static inline Laparc *next_doc(void *headptr, Laparc *ptr)
{
	return ( (lap_next_arc(headptr, ptr)) ?
				lap_next_arc(headptr, ptr) :
				ptr );
}

static inline Laparc *prev_doc(void *headptr, Laparc *ptr)
{
	return ( (lap_prev_arc(headptr, ptr) != NULL) ?
				lap_prev_arc(headptr, ptr) :
				ptr );
}

// text
void viewText(const char *fpath);
void mdReader(const char *fpath);
// exec
void runSh(const char *fpath);
void runBat(const char *fpath);
void runC(const char *fpath);
void runCpp(const char *fpath);
void runPy(const char *fpath);

#endif