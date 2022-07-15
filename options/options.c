#include <stdio.h>
#include <ctype.h>
#include "dcl.h"

void about(void);
void reinstall(void);


void options(void)
{
	while (1)
	{
		clear();
		printf("\n[A]bout\n");
		printf("\n[R]einstall\n");
		printf("\n[B]ack\n");
		printf("\n\ninput: ");
		
		switch (toupper(getchr())) {
		case 'A':
			about();
			break;
		case 'R':
			reinstall();
			break;
		case 'B':
			return;
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