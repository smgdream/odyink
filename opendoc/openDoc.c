#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/def.h"


void openDoc(int id)
{
	while (1)
	{
		clear();
		char *docType;
		char docPath[32];
		sprintf(docPath, "./odydata/doc/%d.%s", id, docType = readType(id));
		if (!strcmp(docType, "txt")) {
			viewText(docPath);
			printf("          [E]dit          \n");
		}
		else if (!strcmp(docType, "sh"))
			;
		else if (!strcmp(docType, "bat"))
			;
		else if (!strcmp(docType, "py"))
			;
		else if (!strcmp(docType, "c"))
			;
		else if (!strcmp(docType, "cpp"))
			;
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