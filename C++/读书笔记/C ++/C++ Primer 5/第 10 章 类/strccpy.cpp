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
	   p[strlen(pstr)] = '\0';*/     // ��Ҫ��Щ���ڼ�+1 ��Ϊ�����Ǵ�0��ʼ

    /* 2. strncpy(p, "xie", 10); */  // �����xie��û��10����  ����xie����ӵ�p��Ȼ��� 6�����ַ�

    strncpy(p, "xie hai bing", 6);     // ������� \0 �������ַ���
	//strcpy_s(pmane, strlen(p)+1, p); // �˰汾���ᱨ����
	p[6] = '\0';

	cout<< p <<endl;

	return 0;
}