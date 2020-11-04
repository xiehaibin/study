#include <cstring>
#include <iostream>
using namespace std;

char *pstr = "xie hai bing";

int main(void)
{
	char *p;

    p = new char[strlen(pstr)+1];
	if (p == NULL)
	{
		cerr<<"error..."<<endl;
	}

	/*1. strncpy(p, "xie", strlen(pstr)+1);
	   p[strlen(pstr)] = '\0';*/     // 不要在些处在加+1 因为数组是从0开始

    /* 2. strncpy(p, "xie", 10); */  // 如果“xie”没有10个字  将“xie”添加到p中然后加 6个空字符

    strncpy(p, "xie hai bing", 6);     // 必须添加 \0 否则不是字符串
	//strcpy_s(pmane, strlen(p)+1, p); // 此版本不会报警告
	p[6] = '\0';

	cout<< p <<endl;

	return 0;
}