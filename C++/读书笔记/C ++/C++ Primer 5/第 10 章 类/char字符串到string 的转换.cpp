#include <string>
#include <cstring>
#include <iostream>
using namespace std;

string& fnString(string & str1,  const string & str2) // string ���� char* ����������
{
	return str1 = str1 + str2;
}

int main (void)
{
	/*char *p = "xie hai bing";   // string�ඨ����һ��char* ��string���ת������ ���ý���������
	string str = p;
	cout<< str <<endl;*/

	/*char ch[20] = "xie hai bin";
	string str = ch;
	cout<< str <<endl;*/


	/*char ch[20] = "xie hai bin"; // ���ַ�ʽ�������ʹ��� strcpy �������ַ������
	string *str;
	strcpy(str, ch);
	cout<< str <<endl;*/

   string str = "xie hia ";

   string str3 = fnString(str, "bing");

   cout<< str3 <<endl;

	return 0;
}