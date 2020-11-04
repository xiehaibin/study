#include <cstring>
#include <iostream>
using namespace std;

class A
{
private :
	char *pstr;
	int a;

public :
	A(char *p = "xie")
	{
		pstr = new char[strlen(p)+1];
		strcpy(pstr, p);
		pstr[strlen(p)] = '\0';

		cout<<"构造：：：：: "<<strlen(p)<<endl;
	}

	A(const A &t, int n)
	{
		pstr = new char[strlen(t.pstr)+1];
		strcpy(pstr, t.pstr);
		pstr[strlen(t.pstr)] = '\0';

		cout<<"构造.................."<<endl;
		a = n;
	}

	void get(void) const
	{
		cout<<"************ : "<<pstr<<endl;
	}

	~A(void)
	{
		delete [] pstr;
	}
};

int main(void)
{
	A a("xie hai");     // 构造：：：：: 
	//a.get();

	A b;                 // 构造：：：：: 
    //b = a;             // 是不可以 如果类中没有动态配的成员是可以这样 因为它将不调用构造函数
	//b.get();           // ************

	A c(a, 4);           // 构造..................
	c.get();             // ************    

	A d = a;             // 构造.................. 如果是两个参数 
	d.get();             // ************ 

	return 0;
}