#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/def.h"

int exopt(char *docPath);
void runSh(const char *fpath);
void runBat(const char *fpath);
void runC(const char *fpath);
void runCpp(const char *fpath);
void runPy(const char *fpath);

void openDoc(int id)
{
	while (1)
	{
		clear();
		char *docType = NULL;
		char docPath[32];

		docType = readType(id);
		getDoc(id, docType);
		sprintf(docPath, "./odydata/doc/%d.%s", id, docType);
		
		if (!strcmp(docType, "txt")) {
			viewText(docPath);
			putchar('\n');
		}
		else if (!strcmp(docType, "sh")) {
			if (exopt(docPath))
				runSh(docPath);
		}
		else if (!strcmp(docType, "bat")) {
			if (exopt(docPath))
				runBat(winPath(docPath));
		}
		else if (!strcmp(docType, "py")) {
			if (exopt(docPath))
				runPy(docPath);
		}
		else if (!strcmp(docType, "c")) {
			if (exopt(docPath))
				runC(docPath);
		}
		else if (!strcmp(docType, "cpp")) {
			if (exopt(docPath))
				runCpp(docPath);
		}
		else if (!strcmp(docType, "nul")) {
			printf("The doc has been deleted\n");
			genSleep(2);
			break;
		}
		else {
			printf("Doc does not exist\n");
			genSleep(2);
			break;
		}
		if (fexist(docPath))
			remove(docPath);
		//
		ipOpt:
		printf("[B]ack    [Q]uit    [N]ext\n");
		printf("\ninput: ");
		switch (toupper(getchr())) {
			case 'N':
				id = nextDoc(id);
				break;
			case 'B':
				id = backDoc(id);
				break;
			case 'Q':
				return;
				break;
			default:
				printf("Input error\n");
				goto ipOpt;
				break;
		}
		continue;
	}
	return;
}

int exopt(char *docPath)
{
	viewText(docPath);
	printf("\n\n");
	printf("Run executable document (y/n):\n");
	if(toupper(getchr()) == 'Y')
		return 1;
	else
		return 0;
}