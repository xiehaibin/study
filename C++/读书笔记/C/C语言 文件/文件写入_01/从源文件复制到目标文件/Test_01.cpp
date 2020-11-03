#include <stdio.h>
#include <stdlib.h>

void my_copy(char str[][30]);

int main(void)
{
	FILE *fp1;
	char c;
	const int how = 20;

	char str[2][30] =
	             {
					 "d:\\Test01.txt",
					 "d:\\Test02.txt"
	             };

	if((fp1=fopen(str[0],"w")) == NULL)  // 写入
	{
		printf("Error..........");
		exit(0);
	}

	for(int i = 0; i < how; i++)
	{
		c = getchar();
		fputc(c,fp1);
	}
    fclose(fp1);  // 下面还要使手 用完后要释放 
	my_copy(str);
	return 0;
}
void my_copy(char str[][30])
{
	FILE *fp1, *fp2;

	if((fp1 = fopen(str[0],"r")) == NULL)
	{
		printf("Error........");
		exit(0);
	}

	if((fp2 = fopen(str[1],"w")) == NULL)
	{
		printf("Error.........");
		exit(0);
	}

	while(!feof(fp1))
		fputc(fgetc(fp1),fp2);

	fclose(fp1);
	fclose(fp2);
}