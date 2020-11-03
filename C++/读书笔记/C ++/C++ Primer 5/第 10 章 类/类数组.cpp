#include <cstring>
#include <iostream>
using namespace std;

class A
{
private :
	int m_a;
	int m_b;
	enum{len = 20};
	char *pstr;

public :
	//A(int a /*= 0*/, int b /*= 0*/, char *p /*= "xie hia"*/) // 不能将*p 的位置放到别区
	//{
 //      pstr = new char[strlen(p)+1];
	//   strncpy(pstr, p, strlen(p));
	//   pstr[strlen(p)] = '\0';

	//	m_a = a;
	//	m_b = b;

	//	cout<<"构造..."<<" : "<< a <<endl;
	//}


	A(int a)
	{
		m_a = a;
		cout<<"构造..."<<" : "<< a <<endl;
	}

	A(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<"构造..."<<" : "<< a <<endl;
	}
	/*A()
	{
		cout<<"默认构造"<<endl;
	}*/



	~A()
	{
		cout<<"析构..."<<" : "<< m_a <<endl;
	}

};

int main(void)
{
    /*A a[5] = 
	{
		A(1, 5, "xie"),
        A(2, 5, "xie hai"),
		A(3, 5, "xie hai b"),
		A(4, 5, "xie hai bi"),
	    // a[4] 会调用默认的构造函数
	}; */


	A b[2] = 
	{
		A(11),
		A(12, 20)
	};

	cout<<endl;
}

// !!！书中说 创建类对象数组 则这类必须有默认的构造函数 此实现并不用?  A* pa[5] 将需要

