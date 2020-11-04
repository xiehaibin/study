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
		cout<<"����"<<endl;
	}

	A()
	{
		cout<<"����A() ............. "<<endl;
	}

	A(A &t)
	{
		a = t.a;

		cout<<" ����A(A &t)************** "<<endl;
	}

	void get(void)const
	{
		cout<< a <<endl;
	}

	~A(void)
	{
		//cout<<"����..."<<endl;
	}
};

int main(void)
{
	A a(100, 100); // ����

	A d = a;  // ����A(A &t)************** û��ʵ��A(A &t)���캯�� ������Ĭ�ϵ�
	d.get();  // 100

	A c(a);   // ����A(A &t)**************
	c.get();  // 100

	A e;        // ����A() .............
	e = a;      // û�е��ù��캯�� ʹ����Ĭ�� = �����
	e.get();    // 100

	return 0;
}