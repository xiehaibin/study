#include <string>
#include <cstring>
#include <iostream>
using namespace std;

string& fnString(string & str1,  const string & str2) // string 引用 char* 将产生副本
{
	return str1 = str1 + str2;
}

int main (void)
{
	/*char *p = "xie hai bing";   // string类定义了一种char* 到string类的转换功能 引用将产生问题
	string str = p;
	cout<< str <<endl;*/

	/*char ch[20] = "xie hai bin";
	string str = ch;
	cout<< str <<endl;*/


	/*char ch[20] = "xie hai bin"; // 这种方式将报类型错误 strcpy 是用于字符数组的
	string *str;
	strcpy(str, ch);
	cout<< str <<endl;*/

   string str = "xie hia ";

   string str3 = fnString(str, "bing");

   cout<< str3 <<endl;

	return 0;
}