#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "lap.h"
#include "opendoc.h"

static int isText(const char *type);
static int isExec(const char *type);
static int openText(const char *path, const char *type);
static int openExec(const char *path, const char *type);
static int docAct(const char *path);

enum OP_TAB{QUIT, PREV, THIS, NEXT};

void open_doc(Laparc *ptr)
{
	while (1) {
		const char *type = lap_get_type(ptr);
		char path[SIZE_BIG + 1];
		int op = 0;

		sprintf(path, "%s/%u.%s", ocfg_doc(oconf), lap_get_id(ptr), type);

		clear();
		if (isText(type)) {
			op = openText(path, type);
		}
		else if (isExec(type)) {
			op = openExec(path, type);
		}
		else {
			printerr("error: undefine type [%s]\n", type);
			gen_sleep(2);
			clear();
			return;
		}
		switch (op) {
		case NEXT:
			ptr = next_doc(ocfg_headptr(oconf), ptr);
			break;
		case PREV:
			ptr = prev_doc(ocfg_headptr(oconf), ptr);
			break;
		case THIS:
			break;
		case QUIT:
			return;
			break;
		}
	}
	return;
}


static int openText(const char *path, const char *type)
{
	if (!strcmp(type, "txt")) {
		viewText(path);
	}
	else if (!strcmp(type, "md")) {
		mdReader(path);
	}
	return docAct(path);
}


static int openExec(const char *path, const char *type)
{
	viewText(path);
	printf("Do you want to run this execable document? [Y/n]");
	if (toupper(getchr()) == 'Y') {
		clear();
		if (!strcmp(type, "sh")) {
			runSh(path);
		}
		else if (!strcmp(type, "bat")) {
			runBat(to_winpath(path));
		}
		else if (!strcmp(type, "c")) {
			runC(path);
		}
		else if (!strcmp(type, "cpp")) {
			runCpp(path);
		}
		else if (!strcmp(type, "py")) {
			runPy(path);
		}
	}
	clear();
	return docAct(path);
}


static int docAct(const char *path)
{
	while (1) {
		printf("\n\n");
		printf("         [E]dit          \n");
		printf("[P]rev   [Q]uit    [N]ext\n");
		printf("\n");
		printf("input: ");

		switch (toupper(getchr())) {
		case 'N':
			return NEXT;
			break;
		case 'P':
			return PREV;
			break;
		case 'E':
			edit_text(path);
			return THIS;
			break;
		case 'Q':
			return QUIT;
			break;
		default:
			printerr("input error\n");
			gen_sleep(1);
			break;
		}
		continue;
	}
	return QUIT;
}


static int isText(const char *type)
{
	if (!strcmp(type, "txt") 
	 || !strcmp(type, "md"))
		return 1;
	else
		return 0;
}


static int isExec(const char *type)
{
	if (!strcmp(type, "sh")
	 || !strcmp(type, "bat")
	 || !strcmp(type, "c")
	 || !strcmp(type, "cpp")
	 || !strcmp(type, "py"))
		return 1;
	else
		return 0;
}


