#ifndef OCFG_H
#define OCFG_H

#ifndef ODYCONF_TYPE
#define ODYCONF_TYPE
struct odyconf;
typedef struct odyconf Odyconf;
#endif

/* 
 * 
 */
Odyconf *ocfg_create(void);

/* 
 * 
 */
Odyconf *ocfg_set_headptr(Odyconf *ptr, void *headptr);

/* 
 * 
 */
Odyconf *ocfg_set_path(Odyconf *ptr, const char *cfg_file);

/* 
 * 
 */
void ocfg_free(Odyconf *ptr);


/* 
 * 
 */
void *ocfg_headptr(Odyconf *ptr);

/* 
 * 
 */
const char *ocfg_data_dir(Odyconf *ptr);

/* 
 * 
 */
const char *ocfg_data_file(Odyconf *ptr);

/* 
 * 
 */
const char *ocfg_doc(Odyconf *ptr);

/* 
 * 
 */
const char *ocfg_log(Odyconf *ptr);

#endif