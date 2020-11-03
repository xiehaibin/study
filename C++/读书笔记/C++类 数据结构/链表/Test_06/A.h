#include <iostream>
using namespace std;

class A
{
public :
	int n;

	A * next;
	A * prior;

	A(int a) :next(NULL), prior(NULL)
	{
		n = a;
	}
};