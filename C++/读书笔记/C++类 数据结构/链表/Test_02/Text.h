#include <iostream>
using namespace std;

class Link
{
public :
	int n;

	Link * next;
	Link * prior;

	Link(int a) :next(NULL), prior(NULL)
	{
		n = a;
	}
};