#include <iostream>
#include <map>
using namespace std;

template<class Type>
class A
{
public :
	map<char*, Type>texList;
	typedef map<char*, Type>::iterator iterator;
	iterator first;

	static A * pa;


	A(){}
	static A* GetInit()
	{
		if (NULL == pa)
		{
			pa = new A<int>;
		}
		return pa;
	}
	
	void fun(void)
	{
		texList['a'] = aa;
		texList['b'] = aa+1;
		texList['x'] = aa+2;
	}

	static void Get()
	{
		typedef map<char*, Type>::iterator iterator;
	    iterator first;
	}

	void set()
	{

	}
};

int main(void)
{
	A<int> a;
	//a.Get();
	return 0;
}