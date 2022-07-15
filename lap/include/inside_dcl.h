#ifndef LAP_INSIDE_DCL_H
#define LAP_INSIDE_DCL_H

int lap__fexist(const char *fpath);
int lap__filecreate(const char *fpath, char flag);
int lap__fcopy(const char *source, const char *target);

char *lap__cat(const char *fmt, ...);

#endif
// #include "inside_dcl.h"