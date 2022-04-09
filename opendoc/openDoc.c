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
	//char ip = '\0';
	while (1)
	{
		int sign = 0;
		clear();
		char *docType = NULL;
		char docPath[32];
		sprintf(docPath, "./odydata/doc/%d.%s", id, docType = readType(id));
		if (!strcmp(docType, "txt")) {
			sign = 1;
			viewText(docPath);
			printf("          [E]dit          \n");
		}
		else if (!strcmp(docType, "sh")) {
			if (exopt(docPath)) {
				//runSh(docPath);
				exopt(docPath);
			}
			
		}
		else if (!strcmp(docType, "bat")) {
		}
		else if (!strcmp(docType, "py")) {
		}
		else if (!strcmp(docType, "c")) {
		}
		else if (!strcmp(docType, "cpp")) {
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
		//
		ipOpt:	
		printf("[B]ack    [Q]uit    [N]ext\n");
		printf("\ninput: ");
		switch (toupper(getchr())) {
			case 'E':
				editText(docPath);
				break;
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
	char ip = '\0';
	printf("[R]un              [E]dit\n");
	printf("\ninput: ");
	ip = toupper(getchr());
	if (ip == 'R')
		return 1;
	else if (ip == 'E')
		editText(docPath);
	else {
		printf("input error\n");
		return 0;
	}
	return 0;
}