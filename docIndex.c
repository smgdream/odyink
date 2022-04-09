#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/def.h"
#include "include/format.h"

void docIndex(void)
{
	char keyword[TITLE_MAX_LEN];
	int findSign = 0;
	char docIp[10];

	while (1) {
		if (findSign == 0) {
			clear();
			viewIndex("./odydata/docindex.ini");
		}
		findSign = 0;
		//
		printf("\n\n[I]mport   [R]ename  [D]elte\n");
		printf("[O]ptions  [S]earch  [E]xit\n");
		printf("\n");
		printf("ID:");
		getstr(docIp, ID_LEN);
		if (!isdigit(docIp[0])) {
			switch (toupper(docIp[0])) {
				case 'I':
					importDoc();
					break;
				case 'R' :
					renameDoc();
					break;
				case 'D':
					deleteDoc();
					break;
				case 'O':
					options();
					break;
				case 'S':
					printf("\nKeyword: ");
					getstr(keyword, TITLE_MAX_LEN);
					clear();
					printf("\nfound %d item\n\n", search(keyword));
					printf("\n[B]ack to index");
					findSign = 1;
					break;
				case 'E':
					return;
					break;
				case 'B':
					findSign = 0;
					break;
				default:
					printf("Input Error\n");
					genSleep(2);
					break;
			}
			continue;
		}
		openDoc(stoi(docIp));
		clear();
	}
	return;
}