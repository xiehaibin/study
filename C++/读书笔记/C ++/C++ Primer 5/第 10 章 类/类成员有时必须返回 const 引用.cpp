#include <iostream>
using namespace std;

class A
{
public :
	int m_a;

	A(int a) : m_a(a){}

	virtual void Get(void) const 
	{
		cout<< "A...." <<endl;
	}
};

class B : public A
{
public :
	int m_b;

	B(int a, int b) : A(a), m_b(b) {}

	virtual void Get(void) const 
	{
		cout<< "B...." <<endl;
	}
}

int main(void)
{
	A* p = new B(1,2);
	return 0;
}