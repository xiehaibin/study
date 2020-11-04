#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fp = NULL;
	const int H = 10;
	char c;

    // 因为要用到‘\’而它是转义字符的特殊性 所以在它前面要用到‘\’;
	if((fp=fopen("d:\\Test01.txt", "w")) == NULL)  
	{
		printf("error");
		exit(0);	
		// 如果fp等于0 就经常的退出 
	}

	for(int i = 0; i < H; i++)
	{
		//c = getchar();
		c = fgetc(stdin); // stdin 是标准输入高备键盘对应的文件型指针
		fputc(c,fp);
	}

	fclose(fp);
	return 0;
}

