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
		if(feof(pf))       // 如果正确的写入字符 返回EOF 值为-1;
			break;
		c = fgetc(pf);     // 从pf所指向的文件当前位置读取单个字符
		//putchar(c);

		fputc(c, stdout); // 将字符写到标准输出设备上（显示器）
		                  // 其中的stdout是标准输出设备显示器对应的文件型指针
	}
	fclose(pf);
	return 0;
}