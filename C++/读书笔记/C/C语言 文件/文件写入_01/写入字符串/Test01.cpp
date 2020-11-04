#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp;
	const int how = 3;
	char str[3][100];

	for(int i = 0; i < how; i++)
		gets(str[i]);
		//fgets(str,100,stdin);
	
	if((fp = fopen("d:\\Test01.txt","w")) == NULL)
	{
		printf("Error.......");
		exit(0);
	}

	for(int i = 0; i < how; i++)
		fputs(str[i], fp);
	fclose(fp);

}