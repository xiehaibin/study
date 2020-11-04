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

class B : public A
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

class C : public A
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

public :
	D(int a, int b, int c) : B(a, b), C(a, b) 
	{
		dd = c;
	}

	virtual void Show(void)
	{
		cout<<"dd: "<< dd <<endl;
	}
};

int main(void)
{
	D d(1,2,3);
	A* pa = NULL;

	//pa = &d;   // d��������A���� ��������ַ��ѡ�� ����ת������ȷ �ػ���ָ����Ѯ
	pa = (B*)&d; // B���A
	pa->Show();

	pa = (C*)&d; // C���A
	pa->Show();
	return 0;
}