#include <iostream>
using namespace std;

class A
{
private :
	int a;

public :
	A(int b, int c)
	{
		a = b;
		cout<<"构造"<<endl;
	}

	A()
	{
		cout<<"构造A() ............. "<<endl;
	}

	A(A &t)
	{
		a = t.a;

		cout<<" 构造A(A &t)************** "<<endl;
	}

	void get(void)const
	{
		cout<< a <<endl;
	}

	~A(void)
	{
		//cout<<"析构..."<<endl;
	}
};

int main(void)
{
	A a(100, 100); // 构造

	A d = a;  // 构造A(A &t)************** 没有实现A(A &t)构造函数 将调用默认的
	d.get();  // 100

	A c(a);   // 构造A(A &t)**************
	c.get();  // 100

	A e;        // 构造A() .............
	e = a;      // 没有调用构造函数 使用了默认 = 运算符
	e.get();    // 100

	return 0;
}