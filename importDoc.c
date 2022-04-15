#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "include/def.h"
#include "include/format.h"

void importDoc(void)
{
	while (1)
	{
		char filePath[256];
		char docPath[32];
		char fileType[4];
		char logs[256];
		char docTitle[TITLE_MAX_LEN + 1];
		char typeIndex[TYPE_INDEX_LEN + 1];
		char titleIndex[INDEX_LEN + 1];
		int newNum;
		int newId;

		clear();
		// Input file path
		printf("[Q] return to the index\n");
		printf("\n");
		printf("Doc path:");
		getstr(filePath, 256);
		strcpy(filePath, rmQuote(unixPath(filePath)));
		if (!strcmp(filePath, "q") || !strcmp(filePath, "Q"))
			break;
		if (!fexist(filePath))
		{
			printf("File does not exist\n");
			genSleep(2);
			continue;
		}

		// Input Doc title
		printf("Doc title:");
		getstr(docTitle, TITLE_MAX_LEN); // Don't change easy
		if (!strcmp(docTitle, "q") || !strcmp(docTitle, "Q"))
			break;
		//
		//Get file Type
		strcpy(fileType, getType(filePath));
		// GetnewID
		newId = fgeti("./odydata/allocid.ini") + 1;
		if (!newId)
		{
			printf("fgeti error");
			continue;
		}
		// GetnewNum
		newNum = fgeti("./odydata/docnum.ini") + 1;
		if (!newNum)
		{
			printf("fgeti error");
			continue;
		}

		// Start import the doc
		// Write the docID
			fnewout("./odydata/allocid.ini", itos(newId));
		// Write the number of doc
			fnewout("./odydata/docnum.ini", itos(newNum));
		// Write the doc type
			sprintf(typeIndex, "%s ", fill(itos(newId), ID_LEN, '0'));
			strcat(typeIndex, fill(fileType, -TYPE_LEN, '0'));
			strcat(typeIndex, "\t");
			faddout("./odydata/doctype.ini", typeIndex);
		// Write the index
			sprintf(titleIndex, "%s.%s", itos(newId), docTitle);
			sprintf(titleIndex, "%s\t", fill(titleIndex, -(INDEX_LEN - 1), '\v'));
			faddout("./odydata/docindex.ini", titleIndex);
		// Copy the doc
			sprintf(docPath, "./odydata/doc/%d.%s", newId, fileType);
			fcopy(filePath, docPath);
		// Write the logs
			sprintf(logs, "%s (UTC)\t %s %s\n", timeStr(UTC), "Import", docTitle);
			faddout("./odydata/odyink.log", logs);
		//
		printf("\nFinish\n");
		genSleep(2);
	}
}
