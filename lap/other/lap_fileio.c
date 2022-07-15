#include <stdio.h>


/* 
 * 
 */
int lap__fexist(const char *fpath)
{
	FILE *fp = fopen(fpath, "r");

	if (fp) {
		fclose(fp);
		return 1;
	}
	else
		return 0;
}

/* 
 * 
 */
int lap__filecreate(const char *fpath, char flag)
{
	FILE *fp = fopen(fpath, (flag == 'b') ? "wb" : "w");
	return ( (fp) ? fclose(fp) : EOF );
}

/* 
 * 
 */
int lap__fcopy(const char *source, const char *target)
{
	typedef unsigned char Byte;
	Byte tfs; // Temp file stream
	
	FILE *fp_src = fopen(source, "rb");
	FILE *fp_dest = fopen(target, "wb");

	// if use the feof() it will write the last byte again
	while (fread(&tfs, sizeof(Byte), 1, fp_src))
		fwrite(&tfs, sizeof(Byte), 1, fp_dest);

	fclose(fp_dest);
	fclose(fp_src);

	return 0;
}