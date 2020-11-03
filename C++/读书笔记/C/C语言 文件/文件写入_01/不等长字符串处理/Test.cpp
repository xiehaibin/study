#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	const int how = 3;
	char str[12];

	if((fp = fopen("d:\\T.txt", "w")) == NULL)
	{
		printf("Error.......");
		exit(0);
	}

	for(int i = 0; i < how; i++)
	{
		gets(str);      // 不保留 ‘\n’而是转换成‘\0’
		fputs(str, fp); 
		fputc('\n',fp);
	}

	if((fp = fopen("d:\\T.txt","r")) == NULL)
	{
		printf("Error........");
		exit(0);
	}

	for(int i = 0; i < 3; i++)
	{
		fgets(str,13,fp);
		puts(str);
	}
	fclose(fp);
	return 0;
}