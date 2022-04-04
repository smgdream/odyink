void arrclean(char *s, int size)
{
	for (int i = 0; i < size; ++i)
		*(s + i) = 0;
	return;
}