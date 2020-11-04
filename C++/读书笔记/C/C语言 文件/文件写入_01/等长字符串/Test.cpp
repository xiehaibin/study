#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	const int how = 3;
	char s[11];

	if((fp = fopen("d:\\Test01.txt","w")) == NULL)
	{
		printf("Error.......");
		exit(0);
	}

	for(int i = 0; i < how; i++)
	{
		//gets(s);
		fgets(s,11, stdin);  // 保留回车换行符 然后加‘\0’
		fputs(s, fp);
	}
	fclose(fp);

	if((fp = fopen("d:\\Test01.txt","r")) == NULL)
	{
		printf("Error........");
		exit(0);
	}

	for(int i = 0; i < 3; i++)
		fgets(s,11,fp);
	puts(s);
	fclose(fp);
	return 0;
}