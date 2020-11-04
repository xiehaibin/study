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

	A(const A &t, int n)
	{
		pstr = new char[strlen(t.pstr)+1];
		strcpy(pstr, t.pstr);
		pstr[strlen(t.pstr)] = '\0';

		cout<<"����.................."<<endl;
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
	A a("xie hai");     // ���죺������: 
	//a.get();

	A b;                 // ���죺������: 
    //b = a;             // �ǲ����� �������û�ж�̬��ĳ�Ա�ǿ������� ��Ϊ���������ù��캯��
	//b.get();           // ************

	A c(a, 4);           // ����..................
	c.get();             // ************    

	A d = a;             // ����.................. ������������� 
	d.get();             // ************ 

	return 0;
}