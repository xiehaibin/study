#include <iostream>
using namespace std;

class A
{
private :
	int ca;

public :
	A(int a) : ca(a) {}
	virtual void Show(void)
	{
		cout<<"ca: "<<ca<<endl;
	}
	virtual~A(){}
};

class B : virtual public A
{
private :
	int cb;

public :
	B(int b, int a) : A(a)
	{
		cb = b;
	}
	virtual void Show(void)
	{
		cout<<"cb: "<< cb <<endl;
	}
	virtual~B(){}
};

class C : virtual public A
{
private :
	int cc;

public :
	C(int c, int a) : A(a)
	{
		cc = c;
	}
	virtual void Show(void)
	{
		cout<<"cc: "<< cc <<endl;
	}
	virtual~C() {}
};

class D : public B, public C
{
private :
	int dd;

	virtual void Data(void)
	{
		B::Show();
		C::Show();
	}

public ://                必须直接调用
	D(int a, int b, int c) : A(a), B(b, c), C(c, b)
	{
		dd = c;
	}

	void Show(void)
	{
		A::Show();
		Data();
	}
};

int main(void)
{
	D d(1,2,3);
	A* pa = NULL;

	pa = &d; 

	pa->Show();
	return 0;
}