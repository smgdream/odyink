#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"
#include "format.h"

enum PT{NEXT, THIS, PREV};

void doc_index(void)
{
	int find_flag = 0;
	int pageturn_flag = THIS;
	Laparc *page = lap_last_arc(ocfg_headptr(oconf));
	char keyword[TITLE_MAX_LEN + 1];
	char ip_str[ID_LEN + 1];

	while (1) {
		clear();

		if (find_flag) {
			printf("\nfound %u item\n\n\n"
				, index_find(ocfg_headptr(oconf), keyword));
			printf("[B]ack to index\n");
			
			find_flag = 0;
		}
		else {
			if (pageturn_flag == NEXT)
				page = nextpage(ocfg_headptr(oconf), page, ROW_PER_PAGE);
			if (pageturn_flag == PREV)
				page = prevpage(ocfg_headptr(oconf), page, ROW_PER_PAGE);
			if (pageturn_flag == THIS)
				thispage(ocfg_headptr(oconf), page, ROW_PER_PAGE);
				
			pageturn_flag = THIS;
			printf("\n\n");
		}
		
		printf("[N]ext               [P]rev\n");
		printf("[I]mport   [R]ename  [D]elte\n");
		printf("[O]ptions  [S]earch  [E]xit\n");
		printf("\n");
		printf("ID:");

		getstr(ip_str, ID_LEN);

		if (isdigit(*ip_str)) {
			Laparc *ptr = lap_arc_get( ocfg_headptr(oconf), stoi(ip_str) );
			if (ptr == NULL) {
				printerr("don't exist document id:%u\n", stoi(ip_str));
				gen_sleep(3);
				clear();
				continue;
			}

			open_doc(ptr);
			continue;
		}

		switch (toupper(*ip_str)) {
		case 'N':
			pageturn_flag = NEXT;
			break;
		case 'P':
			pageturn_flag = PREV;
			break;
		case 'I':
			import_doc();
			page = lap_last_arc(ocfg_headptr(oconf));
			break;
		case 'R' :
			rename_doc();
			break;
		case 'D':
			delete_doc();
			page = lap_last_arc(ocfg_headptr(oconf));
			break;
		case 'O':
			options();
			break;
		case 'S':
			printf("\nKeyword: ");
			getstr(keyword, TITLE_MAX_LEN);
			find_flag = 1;
			break;
		case 'E':
			return;
			break;
		case 'B':
			find_flag = 0;
			break;
		default:
			printerr("input error\n");
			gen_sleep(2);
			break;
		}
		continue;
	}
	return;
}
