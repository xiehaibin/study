#pragma once
#include <cstring>
#include "Cbox.h"
#include <iostream>
using namespace std;

class Minbox : public Cbox
{
private:
	char* pmane;
	int x;
	int y;

public:
	Minbox(char* p = "xie", int a = 0, int b = 0, int c = 0) : Cbox(a, b, c)
	{
		pmane = new char[strlen(p)+1];
		strcpy_s(pmane, strlen(p)+1, p);
		//cout<< pmane <<"........."<<endl;
	}

	void Get(void) const
	{
		cout<< pmane <<endl;
	}

	friend void fun(const Minbox & box);

	~Minbox(void)
	{
		//cout<< pmane <<"....Îö¹¹...."<<endl;
		delete [] pmane;
	}
};