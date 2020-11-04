#include <iostream>
using namespace std;

namespace str
{
	int a = 10;
	void fun();
}

namespace str // 可以在不同的地方添加
{
	int b = 100;
}

int a = 110;

int main(void)
{
	using namespace str;
	//int a = 1110; // 加上此句后 结果: 1110,  110;
	cout<<"name: "<< a <<endl;
	cout<<"main: "<<::a <<endl; // 将显于“a”: 不明确的符号
	cout<<"b："<<b<<endl;
	return 0;
}
namespace str
{
	void fun()
	{	cout<<" ### "<<a<<endl; }
}
