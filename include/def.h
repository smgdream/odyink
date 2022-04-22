#ifndef DEF_H
#define DEF_H

#include "ostype.h"
#define _CRT_SECURE_NO_WARNINGS
#define UTC 0


void install(void);
void docIndex(void);


// Open Document
	void openDoc(int id);
//

// User options
	void options(void);
	void help(void);
	void about(void);
	void changeWebsite(void);
	void uninstall(void);
//

// OS Commands
	void clear(void);
	void cmdInit(void);
	void cmdRestore(void);
	void delAllDoc(void);
	void genSleep(int second);
//

// Network
	int webGet(const char *url, const char *savePath);
	int getData(const char *url);
	int getDoc(int id, const char *type);
	void writeUrl(void);
	const char *getUrl(const char *fpath);
//

// Files Manipulation
	int fexist(char *fpath);
	void fcopy (char *source,char *target);
	void fnewout(char *fpath,char *text);
	void faddout(char *fpath,char *text);
	int fgeti(char *fpath);
	void viewText(char *fpath);
	void viewIndex(char *fpath);
	char *readType(int docId);
	int getstr(char *Buf, int MaxCount);
	char getchr(void);
	int search(char *keyword);
	int backDoc(int id);
	int nextDoc(int id);
	void cleanData(void);
//

// Process
	int stoi(char *numstr);
	char *itos(int number);
	//char *timeStr(int zone);
	char *rmQuote(char *s);
	void arrclean(char *s, int size);
	char *getType(char *fpath);
	//char *fill(char *string, int size, char ch);
	char *unixPath(char *fpath);
	char *winPath(char *fpath);
	// char *crlfto0(char *string);
	// char *reverse(char *string);
//

//Other
//

#endif