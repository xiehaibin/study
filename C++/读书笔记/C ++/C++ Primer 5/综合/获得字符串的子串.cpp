#include <string>
#include <iostream>

int main( ) 
{
   using namespace std;

   string  str1 ("Heterological paradoxes are persistent.");
   cout << "The original string str1 is: \n " << str1
        << endl << endl;

// basic_string substr( size_type index, size_type num = npos );
// substr()返回本字符串的一个子串，从index开始，长num个字符。如果没有指定，
// 将是默认值 string::npos。这样，substr()函数将简单的返回从index开始的剩余的字符串。
   basic_string <char> str2 = str1.substr ( 6 , 7 );
   cout << "The substring str1 copied is: " << str2
        << endl << endl;
   
   basic_string <char> str3 = str1.substr (  ); // 返回所有的字符串
   cout << "The default substring str3 is: \n " << str3
        <<  "\n which is the entire original string." << endl;
}
