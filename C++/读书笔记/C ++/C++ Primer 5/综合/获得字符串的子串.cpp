#include <string>
#include <iostream>

int main( ) 
{
   using namespace std;

   string  str1 ("Heterological paradoxes are persistent.");
   cout << "The original string str1 is: \n " << str1
        << endl << endl;

// basic_string substr( size_type index, size_type num = npos );
// substr()���ر��ַ�����һ���Ӵ�����index��ʼ����num���ַ������û��ָ����
// ����Ĭ��ֵ string::npos��������substr()�������򵥵ķ��ش�index��ʼ��ʣ����ַ�����
   basic_string <char> str2 = str1.substr ( 6 , 7 );
   cout << "The substring str1 copied is: " << str2
        << endl << endl;
   
   basic_string <char> str3 = str1.substr (  ); // �������е��ַ���
   cout << "The default substring str3 is: \n " << str3
        <<  "\n which is the entire original string." << endl;
}
