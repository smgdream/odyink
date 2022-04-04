#include <stdio.h>
#include "../include/def.h"

#define SIZE_BIG 1024 * 4


static char bufL2[SIZE_BIG + 1];	// Buffer level 2



int getcUTF8(char *bl1, FILE *fp)
{
	size_t readTextWithBuf(FILE *fp);
	static int buf2i = 0;
	int sign = 1;
	char tc = '\0';
	arrclean(bl1, 5);

	while (1) {
		if ((tc = bufL2[buf2i]) == '\0') {
			if (readTextWithBuf(fp) == 0)
				return EOF;
			buf2i = 0;
			tc = bufL2[buf2i];
		}
		if ((tc & 0xC0) != 0x80)	// 10XX XXXX & 1100 0000 == 1000 0000
			sign *= -1;
		if (sign == 1) {
			*bl1++ = '\0';
			return 0;
		}
		*bl1++ = tc;
		++buf2i;
	}
}

size_t readTextWithBuf(FILE *fp)
{
	size_t n = 0;

	n = fread(bufL2, 1, SIZE_BIG, fp);
	bufL2[n] = '\0';
	return n;
}