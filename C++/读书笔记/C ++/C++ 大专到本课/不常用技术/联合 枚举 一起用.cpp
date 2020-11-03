#include <iostream>
using namespace std;

union un
{
	int a;
	double d;
	enum en{one = 1, two = 2};
};

// 可用于游戏按键的使用
int main (void)
{
	un ion;
	ion.a = 100;

	cout<< ion.a <<endl;

	ion.d = 1.10;
	cout<< ion.d <<endl;

	cout<< sizeof(ion) <<endl;

	cout<< ion.one <<endl;
	cout<< ion.two <<endl;
	return 0;
}