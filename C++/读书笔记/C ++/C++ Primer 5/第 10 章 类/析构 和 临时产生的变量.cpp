#include <cstring>
#include <iostream>
using namespace std;

class A
{
private :
	int i_a;

public :
	A()
	{
		i_a = 0;
		cout<<"A()..."<<i_a<<endl;
	}

	A(int a)
	{
		i_a = a;
		cout<<"A(int a)..."<<i_a<<endl;
	}

	~A()
	{
		cout<<"析构...."<<i_a<<endl;
	}
};

int main(void)
{
	A a;
	A b(100);
	a = A(200);
	cout<<"----------------"<<endl;
}
// 输出
// A()...0         a
// A(int a)...100  b
// A(int a)...200  a = A(200)

// 析构....200     a = A(200) 时会产生临时的对象
// --------------------
// 析构....100     b
// 析构....200     a

// !!!如果可通过初始化 同时也可以通过赋值来初始化对象 则应采用初始化方式
// 通常这种方式的效率更高

