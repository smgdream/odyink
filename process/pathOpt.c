#include "../include/def.h"

#define strcopy(_T, _S) {\
	int _i = 0;\
	for (char *_t = _T, *_s = _S; (*(_t + _i) = *(_s + _i)); ++_i)\
		;\
}
#define SIZE_BIG 1024


char *winPath(char *fpath)
{
	static char tmpePath[SIZE_BIG];
	arrclean(tmpePath, SIZE_BIG);
	strcopy(tmpePath,fpath);

	for (int i = 0;tmpePath[i] !='\0';++i) {
		if (tmpePath[i] =='/')
			tmpePath[i] = '\\';
	}
	return tmpePath;
}


char *unixPath(char *fpath)
{
	static char tmpePath[SIZE_BIG];
	arrclean(tmpePath, SIZE_BIG);
	strcopy(tmpePath,fpath);

	for (int i = 0;tmpePath[i] !='\0';++i) {
		if (tmpePath[i] =='\\')
			tmpePath[i] = '/';
	}
	return tmpePath;
}

char *rmQuote(char *s)
{
	int i = 0;
	static char tmpstr[SIZE_BIG];
	char *rmqs = tmpstr;
	arrclean(tmpstr, SIZE_BIG);
	strcopy(tmpstr, s);

	for (; rmqs[0] != '\'' && rmqs[0] != '"' && rmqs[0] != '\0'; ++rmqs)
		;
	if (rmqs[0] != '\0') {
		++rmqs;
		for (i = 0; rmqs[i] != '\'' && rmqs[i] != '"' && rmqs[i] != '\0'; ++i)
			;	
		if (rmqs[i] != '\0') {
			rmqs[i] = '\0';
			return rmqs;
		}
	}
	return s;
}
