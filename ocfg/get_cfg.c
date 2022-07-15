#include "ocfg_type.h"

/* 
 * 
 */
void *ocfg_headptr(Odyconf *ptr)
{
	return ptr->headptr;
}

/* 
 * 
 */
const char *ocfg_data_dir(Odyconf *ptr)
{
	return ptr->path.data_dir;
}

/* 
 * 
 */
const char *ocfg_data_file(Odyconf *ptr)
{
	return ptr->path.data_file;
}

/* 
 * 
 */
const char *ocfg_doc(Odyconf *ptr)
{
	return ptr->path.doc;
}

/* 
 * 
 */
const char *ocfg_log(Odyconf *ptr)
{
	return ptr->path.log;
}