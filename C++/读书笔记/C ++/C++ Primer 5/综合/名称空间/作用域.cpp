#include <iostream>
using namespace std;

namespace str
{
	int a = 10;
	void fun();
}

namespace str // �����ڲ�ͬ�ĵط����
{
	int b = 100;
}

int a = 110;

int main(void)
{
	using namespace str;
	//int a = 1110; // ���ϴ˾�� ���: 1110,  110;
	cout<<"name: "<< a <<endl;
	cout<<"main: "<<::a <<endl; // �����ڡ�a��: ����ȷ�ķ���
	cout<<"b��"<<b<<endl;
	return 0;
}
namespace str
{
	void fun()
	{	cout<<" ### "<<a<<endl; }
}
