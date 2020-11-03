#include <iostream>
using namespace std;

const char c_ch = 'x';

int main(void)
{
	char ch = ch;

	cout<<"请输入一个字符：";

	while(cin.get(ch))
	{
		if(ch == c_ch)
		{
			cout<<"你输入对了 加10分!"<<endl;
			exit(0);
		}
		else
		{
			cout<<"error...."<<endl;
			cout<<"请重生输入：";
			ch = cin.get();
		}
	}
	return 0;
}
-------- 1 -------------
//char ch;
//cin.get(ch);
//while(cin.fail() == false)
//{
//	cout<<ch;
//	++i;
//	cin.get(ch);
//}

-------- 2 ------------
//int ch;
//ch = cin.get();
//while(ch != EOF)
//{
//	cout.put(ch);
//	++i;
//	ch = cin.get();
//}