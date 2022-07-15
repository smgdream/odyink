#ifndef DCL_H
#define DCL_H

#include <stdio.h>
#include "sizedef.h"
#include "ostype.h"
#include "format.h"
#include "lap.h"
#include "ocfg.h"

#define _CRT_SECURE_NO_WARNINGS
#define CONFIG_PATH "./"
#define UTC 0

extern Odyconf *oconf;

void install_ody(void);
void doc_index(void);
void import_doc(void);
void delete_doc(void);
void rename_doc(void);
void open_doc(Laparc *ptr);
void options(void);


// lap operation
	uint32_t index_print(void *headptr);
	uint32_t index_find(void *headptr, const char *keyword);
	Laparc *nextpage(void *headptr, Laparc *ptr, int lines);
	Laparc *prevpage(void *headptr, Laparc *ptr, int lines);
	Laparc *thispage(void *headptr, Laparc *ptr, int lines);
//


//OS Commands
	void clear(void);
	void cmd_init(void);
	void cmd_restore(void);
	void gen_sleep(int seconds);
	int edit_text(const char *fpath);
	int mkdir(const char *dir);
//

// Files operation
	int fexist(const char *fpath);
	int filecreate(const char *fpath, char flag);
	int fnewout(const char *fpath, const char *text);
	int faddout(const char *fpath, const char *text);
	int fcopy(const char *source, const char *target);
	int fgeti(const char *fpath);
	void logger(const char *log);
	
	char *read_type(int docId);
	char *getstr(char *s, int n);
	char getchr(void);
	char *file_getline(char *s, int n, FILE *stream);
//

// Process
	int stoi(const char *numstr);
	char *itos(int number);
	const char *timestr(int zone);
	char *rm_quote(const char *s);
	void arrclean(char *s, int size);
	const char *get_filetype(const char *fpath);
	char *to_unixpath(const char *fpath);
	char *to_winpath(const char *fpath);
	char *fmt_path(char *path);
	char *cat(const char *fmt, ...);
//

// Other
	const char *str2ptr(const char *s);
	#define printerr(...) fprintf(stderr, __VA_ARGS__)
//

#endif