#ifndef LAP_BASE_H
#define LAP_BASE_H

#include <stdint.h>
#include "lap_def.h"


struct laparc;
typedef struct laparc Laparc;

///////////////////////////////////////////////////////////////////////////////
/* 
 * 
 */
int lap_init_data(const char *datafile);

/* 
 * 
 */
void *lap_load_data(const char *datapath);

/* 
 * 
 */
int lap_save_data(void *headptr, const char *datapath);

/* 
 * 
 */
int lap_close_data(void *headptr);

///////////////////////////////////////////////////////////////////////////////
/* 
 * 
 */
int lap_arc_add(void *headptr, const char* type, const char *title
				, const char *src, const char *dest);

/* 
 * 
 */
int lap_arc_change(Laparc *ptr, const char *type, const char *title
					, const char *src, const char *dest);

/* 
 * 
 */
int lap_arc_remove(Laparc *ptr, const char *dir);

/* 
 * 
 */
int lap_arc_set(Laparc *ptr, uint32_t id
	, const char *type, const char *title);

///////////////////////////////////////////////////////////////////////////////
/* 
 * 
 */
Laparc *lap_arc_get(void *headptr, uint32_t id);

/* 
 * 
 */
Laparc *lap_first_arc(void *headptr);

/* 
 * 
 */
Laparc *lap_last_arc(void *headptr);

/* 
 * 
 */
Laparc *lap_next_arc(void *headptr, Laparc *ptr);

/* 
 * 
 */
Laparc *lap_prev_arc(void *headptr, Laparc *ptr);

///////////////////////////////////////////////////////////////////////////////
/* 
 * 
 */
uint32_t lap_get_id(Laparc *ptr);

/* 
 * 
 */
const char *lap_get_type(Laparc *ptr);

/* 
 * 
 */
const char *lap_get_title(Laparc *ptr);

///////////////////////////////////////////////////////////////////////////////
/* 
 * 
 */
uint32_t lap_arc_total(void *headptr);


#endif