#include <cstring>
#include <iostream>
using namespace std;

class A
{
private :
	int i_a;

public :
	A()
	{
		i_a = 0;
		cout<<"A()..."<<i_a<<endl;
	}

	A(int a)
	{
		i_a = a;
		cout<<"A(int a)..."<<i_a<<endl;
	}

	~A()
	{
		cout<<"����...."<<i_a<<endl;
	}
};

int main(void)
{
	A a;
	A b(100);
	a = A(200);
	cout<<"----------------"<<endl;
}
// ���
// A()...0         a
// A(int a)...100  b
// A(int a)...200  a = A(200)

// ����....200     a = A(200) ʱ�������ʱ�Ķ���
// --------------------
// ����....100     b
// ����....200     a

// !!!�����ͨ����ʼ�� ͬʱҲ����ͨ����ֵ����ʼ������ ��Ӧ���ó�ʼ����ʽ
// ͨ�����ַ�ʽ��Ч�ʸ���

