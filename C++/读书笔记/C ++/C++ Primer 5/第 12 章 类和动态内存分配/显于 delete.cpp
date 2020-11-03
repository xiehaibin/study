#include<iostream>
#include <cstring>
using namespace std;

const int MAX = 512;

class A
{
public :
	char* pstr;

	A(char* p = "xie", int n = 1)
	{
		pstr = new char[strlen(p)+1];
		strcpy(pstr, p);
	}

	~A(void)
	{
		cout<< pstr <<endl;
	}
};

int main()
{
	char* pc = new char[MAX];

	A *p1 = new A("p1........", 1);

	A *p2 = new (pc) A("p2.........", 2);

	A *p3 = new (pc + sizeof(*p2)) A("p3..........", 3);

	delete p1;
	//delete p2;
	//delete p3;
	p2->~A();   // 显于delete  注意 先创建的 后delete 
	p3->~A();
	delete pc;
}
