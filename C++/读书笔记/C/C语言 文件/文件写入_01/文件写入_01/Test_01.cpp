#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp = NULL;
	const int H = 10;
	char c;

    // ��ΪҪ�õ���\��������ת���ַ��������� ��������ǰ��Ҫ�õ���\��;
	if((fp=fopen("d:\\Test01.txt", "w")) == NULL)  
	{
		printf("error");
		exit(0);	
		// ���fp����0 �;������˳� 
	}

	for(int i = 0; i < H; i++)
	{
		//c = getchar();
		c = fgetc(stdin); // stdin �Ǳ�׼����߱����̶�Ӧ���ļ���ָ��
		fputc(c,fp);
	}

	fclose(fp);
	return 0;
}

