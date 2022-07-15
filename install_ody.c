#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "format.h"
#include "sizedef.h"
#include "install_info_type.h"


enum steps{START, SET_DATA_PATH, READY_TO_INSTALL, INSTALL, FINISH, END};

static unsigned int step(unsigned int st);
static int start(void);
static int set_data_path(void);
static int ready_to_install(void);
static int install(void);
static int finish(void);
static int set_info_path(char *s);
static int add_doc(void);

struct installInfo info;


void install_ody(void)
{
	clear();
	for (unsigned int st = START; (st = step(st)) != END;)
		;
	return;
}


static unsigned int step(unsigned int st)
{
	clear();

	switch (st) {
	case START:
		st += start();
		break;
	case SET_DATA_PATH:
		st += set_data_path();
		break;
	case READY_TO_INSTALL:
		st += ready_to_install();
		break;
	case INSTALL:
		st += install();
		break;
	case FINISH:
		st += finish();
		break;
	}

	return st;
}


static int start(void)
{
	clear();
	printf("Welcome to Odyink\n");
	printf("Enter to continue OR [Q] to quit\n");

	if (toupper(getchr()) == 'Q') {
		clear();
		exit(0);
	}

	return 1;
}

static int set_data_path(void)
{
	char tmpstr[SIZE_BIG + 1];

	clear();
	printf("./odydata/ AS default data path\n\n");

	printf("Enter to using default\n");
	printf("[Q]uit      [B]ack\n\n");

	printf("Data path: ");

	getstr(tmpstr, SIZE_BIG + 1);
	if (!strcmp(tmpstr, "q") || !strcmp(tmpstr, "Q")) {
		clear();
		exit(0);
	}
	else if (toupper(*tmpstr) == 'B') {
		return -1;
	}
	set_info_path(tmpstr);
	return 1;
}

static int ready_to_install(void)
{
	clear();
	printf("Enter to be start install\n");
	printf("[Q]uit      [B]ack\n");

	switch ( toupper(getchr()) ) {
	case 'Q':
		clear();
		exit(0);
	case 'B':
		return -1;
	default:
		clear();
		return 1;
	}
}

static int install(void)
{
	mkdir(CONFIG_PATH);
	fnewout(CONFIG_PATH"/ody_path.ini", info.path.data_dir);
	mkdir(info.path.data_dir);
	mkdir(info.path.doc);
	filecreate(info.path.index, 'b');
	add_doc();
	faddout(info.path.log, cat("%s+08:00\tInstall Odyink\n", timestr(UTC)));
	return 1;
}

static int finish(void)
{
	clear();
	printf("Odyink has been installed\n");
	printf("Enter to be continue\n");
	getchr();
	clear();
	return 1;
}

static int set_info_path(char *tmpstr)
{
	strcpy(tmpstr, to_unixpath(fmt_path(tmpstr)));
	if (*tmpstr == '\0')
		strcpy(info.path.data_dir, "./odydata/");
	else
		strcpy(info.path.data_dir, tmpstr);
	strcpy(info.path.index, cat("%s/%s", info.path.data_dir, "index.dat"));
	strcpy(info.path.doc, cat("%s/%s", info.path.data_dir, "doc/"));
	strcpy(info.path.log, cat("%s/%s", info.path.data_dir, "odyink.log"));
	return 0;
}

static int add_doc(void)
{
	lap_init_data(info.path.index);
	void *headptr = lap_load_data(info.path.index);
	lap_arc_add(headptr, "nofile", "Hello odyink", NULL, NULL);
	lap_arc_set(lap_first_arc(headptr), LAP_NOID, "txt", NULL);
	lap_save_data(headptr, info.path.index);

	fnewout(cat("%s/%s", info.path.doc, "0.txt"),
			"Hello this is Odyink\n"
			"\n"
			"Odyink is make by smgdream\n");
			
	return 0;
}
