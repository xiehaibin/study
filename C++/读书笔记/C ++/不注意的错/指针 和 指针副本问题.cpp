#include <iostream>
#include <cstring>
using namespace std;

extern "C" { void fun(char ch1[], char *pstr); }

int main(void)
{
	char ch1[15] = "xie hai bin";
	char *pstr   = "c";             // char *pstr

	cout<< &pstr <<" : "<<*pstr <<endl; 

    fun(ch1, pstr);

	if (pstr == NULL)                 // pstr NULL
		cout<<"##############"<<endl;
	else
	    cout<< pstr <<endl;   

	return 0;
}
void fun(char ch1[], char *pstr)    
{
	cout<< &pstr <<" : "<< pstr <<endl;
	pstr = new char[strlen(ch1)+1];
    	strcpy(pstr, ch1);

	cout<< pstr <<endl;
}

/*
*  fun(ch1, pstr) ���� void fun(char ch1[], char *pstr) pstr������һ������
*  �������Ҳ��ָ��c�� �� new char[strlen(ch1)+1]; �����е� pstr ָ���˸�
*  NOW �������Ŀ��ڴ� ��main �����е� pstr ����ָ�� "c"
*/
