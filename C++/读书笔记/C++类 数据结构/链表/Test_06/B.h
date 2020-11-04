#pragma once
#include <iostream>
using namespace std;

class B
{
public :
	double n;

	B * next;
	B * prior;

	B(double a) : next(NULL), prior(NULL)
	{
		n = a;
	}
};