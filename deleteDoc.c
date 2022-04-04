#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/def.h"
#include "include/format.h"


void deleteDoc(void)
{
	while (1)
	{
		// Init
		int docId = 0;
		char delYN = 'n';
		char docIp[10];
		char delDoc[32];
		char logs[256];
		clear();

		// Show the index
		viewIndex("./odydata/docindex.ini");
		// Enter the ID of doc will be delete
		printf("\n[Q] return to the index\n");
		printf("\n");
		printf("DocID:");
		getstr(docIp, 10);
		if (islower(docIp[0]) || isupper(docIp[0]))
		{
			if (toupper(docIp[0]) == 'Q')
				return;
			printf("Input error\n");
			genSleep(2);
			continue;
		}
		docId = stoi(docIp);
		if (docId == -1)
			break;
		sprintf(delDoc, "./odydata/doc/%d.%s", docId, readType(docId));
		if (!fexist(delDoc))
		{
			if (!strcmp(readType(docId), "nul"))
			{
				printf("The doc has been deleted\n");
				genSleep(2);
			}
			else
			{
				printf("Doc does not exist\n");
				genSleep(2);
			}
			continue;
		}

		// Sure to delete
		
		printf("Sure to delete (y/n):");
		delYN = getchr();
		if (toupper(delYN) != 'Y')
			continue;
		// Start del
		fnewout("./odydata/docnum.ini", itos(fgeti("./odydata/docnum.ini") - 1));
		typeCov(docId, "nul");
		indexCov(docId, fill("\v", INDEX_LEN, '\v'));
		remove(delDoc);
		// Write the logs
		sprintf(logs, "%s (UTC)\t %s %d\n", timeStr(UTC), "Delete", docId);
		faddout("./odydata/odyink.log", logs);
		printf("\nFinish\n");
		genSleep(2);
	}
}