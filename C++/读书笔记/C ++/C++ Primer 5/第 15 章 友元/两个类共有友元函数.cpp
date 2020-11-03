#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class B;

class A
{
private :
	int time;

public :
	A(void) 
	{
		time = rand() % 100;
	}

	friend void Show(A &a, B &b);
};

class B
{
private :
	int time;

public :
	B(void) 
	{
		time = rand() % 100;
	}

	friend void Show(A &a, B &b);
};

void Show(A &a, B &b)
{
	cout<< a.time <<endl<< b.time <<endl;
}

int main(void)
{
	srand((unsigned int)time(0));
	A a;
	B b;

	Show(a, b);
	return 0;
}