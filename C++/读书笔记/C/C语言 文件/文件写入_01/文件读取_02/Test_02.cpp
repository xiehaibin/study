#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* pf;
	const int HOW = 30;
	char c;

	if((pf=fopen("d:\\Test01.txt","r")) == NULL)
	{
		printf("Error......");
		exit(0);
	}

	for(int i = 0; i < HOW; i++)
	{
		if(feof(pf))       // �����ȷ��д���ַ� ����EOF ֵΪ-1;
			break;
		c = fgetc(pf);     // ��pf��ָ����ļ���ǰλ�ö�ȡ�����ַ�
		//putchar(c);

		fputc(c, stdout); // ���ַ�д����׼����豸�ϣ���ʾ����
		                  // ���е�stdout�Ǳ�׼����豸��ʾ����Ӧ���ļ���ָ��
	}
	fclose(pf);
	return 0;
}