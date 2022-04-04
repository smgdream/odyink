#include <stdio.h>
#include <ctype.h>
#include "../include/def.h"

void options(void)
{
	while (1)
	{
		clear();
		printf("\n[H]elp\n");
		printf("\n[A]bout\n");
		printf("\n[R]einstall\n");
		printf("\n[U]ninstall\n");
		printf("\n[B]ack\n");
		printf("\n\ninput: ");
		switch (toupper(getchr())) {
			case 'H':
				help();
				break;
			case 'A':
				about();
				break;
			case 'R':
				reinstall();
				break;
			case 'U':
				uninstall();
				break;
			case 'B':
				return;
				break;
			default:
				printf("Input Error\n");
				genSleep(2);
				break;
		}
		continue;
	}
}