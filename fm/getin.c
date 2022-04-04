#include <stdio.h>

#define SIZE_MED 256
#define SIZE_BIG 1024

/* 一次性把缓冲区中所有字符(需小于256)读入临时数组但只返回第一个字符 */
char getchr(void)
{
	int i = 0;
	char ch = '\0';
	char tc = '\0';

	while ((tc = fgetc(stdin)) != '\n' && tc != EOF)
		if (i++ == 0)
		ch = tc;
	return ch;
}

/* 本函数最多读入size - 1个字符入数组
 * 当遇到换行符时用'\0'替换并结束读入返回s
 * --size即为所要的size - 1
 * 一次性把缓冲区中所有字符(需小于1024)读入临时数组
 * 最多复制size - 1个字符到s以'\0'结尾 */
int getstr(char *s, int size)
{
	int i = 0;
	--size;

	char buf[SIZE_BIG];
	while ((buf[i] = fgetc(stdin)) != '\n' && buf[i] != EOF && i < SIZE_BIG)
		++i;
	for (i = 0; i < size && (*(s + i) = *(buf + i)) != '\n'; ++i)
		;
	*(s + i) = '\0';
	return sizeof s;
}
