#include <iostream>
using namespace std;

class A
{
private :
	int a;

public :
	A()
	{
		 Get();
		 Getstatic();
	}

	void Get(void)
	{
		cout<<"*********************"<<endl;  // 1
	}

	void Getstatic(void)
	{
		cout<<"#####################"<<endl; // 2
	}
};

A a;

int main(void)                              // 3
{
    cout<<"main (void)"<<endl;
	return 0;
}