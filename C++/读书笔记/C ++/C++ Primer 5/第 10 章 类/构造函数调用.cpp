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
	//A(int a /*= 0*/, int b /*= 0*/, char *p /*= "xie hia"*/) // ���ܽ�*p ��λ�÷ŵ�����
	//{
 //      pstr = new char[strlen(p)+1];
	//   strncpy(pstr, p, strlen(p));
	//   pstr[strlen(p)] = '\0';

	//	m_a = a;
	//	m_b = b;

	//	cout<<"����..."<<" : "<< a <<endl;
	//}


	A(int a)
	{
		m_a = a;
		cout<<"����..."<<" : "<< a <<endl;
	}

	A(int a, int b)
	{
		m_a = a;
		m_b = b;
		cout<<"����..."<<" : "<< a <<endl;
	}
	/*A()
	{
		cout<<"Ĭ�Ϲ���"<<endl;
	}*/



	~A()
	{
		cout<<"����..."<<" : "<< m_a <<endl;
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
	    // a[4] �����Ĭ�ϵĹ��캯��
	}; */


	A b[2] = 
	{
		A(11),
		A(12, 20)
	};

	cout<<endl;
}

// !!������˵ ������������� �����������Ĭ�ϵĹ��캯�� ��ʵ�ֲ�����?  A* pa[5] ����Ҫ

