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

		cout<<"���죺������: "<<strlen(p)<<endl;
	}

	/*A(const A &t)
	{
		pstr = new char[strlen(t.pstr)+1];
		strcpy(pstr, t.pstr);
		pstr[strlen(t.pstr)] = '\0';

		cout<<"����.................."<<endl;
	}*/

	void get(A a) const
	{
		cout<< a.pstr <<endl;
	}

	~A(void)
	{
		cout<<"%%%%%%%%%"<<endl;
		delete [] pstr;
	}
};

int main(void)
{
	A a("xie hai bing");
	A b;
	b.get(a);   // ������  ���� �� ���� ��û�д� ������ʱ���� ������ĵĴ��뽫�ܰ�ȫ������
	            // ��Ϊ���������ǰ�ֵ���ݵ� ��������������ʱ������ԭ����ָ��ͬһ����̬����ĳ�Աpstr�� 
	            // ��������ʱ������ ���󸴱������� �Ӷ�����̬
	            // ����Ķ�Ա4�ŵ�   ͬ����ָ��Ķ�̬��Ա�����ڴ���

	// !!�������̬Ϊ����C++��ĳ�Ա����ռ� �����ʵ�ָ�ȱ���캯��

	return 0;
}