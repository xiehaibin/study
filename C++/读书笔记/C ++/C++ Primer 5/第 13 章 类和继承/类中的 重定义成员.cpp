#include <iostream>
using namespace std;

class A
{
public :
	int aa;

	typedef int _int;
	struct stt
	{
		int a;
		int b;
		void std(int i, int j)
		{
			a = i;
			b = j;
		}
	};

	A(int a) : aa(a)
	{}
	virtual  void Show(void) = NULL;
	void Get(void)
	{
		Show();
	}
};

class B : public A
{
public :
	int bb;
	typedef int _Int;

	B(int a, int b) : A(a)
	{
		b = b;
	}

	virtual void Show(void)
	{
		cout<<"Show....class B"<<endl;
	}
};

int main(void)
{
	B b(100, 200);
	b.Get(); // 调用子类的

	A::_int a1 = 111;  // 是可以用类名来使用的
	B::_Int b1 = 222;
	
	cout<< a1 <<endl;
	cout<< b1 <<endl;
	return 0;
}