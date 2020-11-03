#include <iostream>
using namespace std;

class A
{
	int as;
public :
	A(int a)
	{
		as = a;
	}
	void show(void(*p)(void))
	{
		cout<< "A "<<endl;
		p();
	}

};

class B
{
	int bs;
	A * pa;

public :

	B(int b)
	{
		bs = b;
		pa = new A(111);
	}

    static void show(void)  // 只能是静态的
	{
		cout<< "B" <<endl;
	}

	void good(void)
	{
		pa->show(show);
	}

};


void tex(void)
{
	cout << "good..." <<endl;
}

void fun(void (*p)(void))
{
	p();
}

int main(void)
{
	A a(10);
	B b(20);
	b.good();
	return 0;
}