#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	char s[21];

	if((fp = fopen("d:\\Test01.txt", "r")) == NULL)
	{
		printf("Error.......");
        exit(0);
	}

	fgets(s,9,fp);
	fputs(s, stdout);
	fclose(fp);
	return 0;
}