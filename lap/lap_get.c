#include "lap_base.h"
#include "chain.h"


/* 
 * 
 */
uint32_t lap_get_id(Laparc *ptr)
{
	return ptr->id;
}

/* 
 * 
 */
const char *lap_get_type(Laparc *ptr)
{
	return ptr->type;
}

/* 
 * 
 */
const char *lap_get_title(Laparc *ptr)
{
	return ptr->title;
}