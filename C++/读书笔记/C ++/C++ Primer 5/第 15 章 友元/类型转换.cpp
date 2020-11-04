#include <iostream>
using namespace std;

class A
{
public :
	int ca;
public :
	A(int a) : ca(a) {}
	A() {}
	virtual void Show(void) { cout<< ca <<endl; }
};

class B : public A
{
private :
	int cb;
public :
	B(int a, int b) : cb(b), A(a) {}
	virtual void Show(void) 
	{
		A::Show();
		cout<< cb <<endl;
	}
};

int main(void)
{
	A a(2);
	B b(10, 20);

	A* pa = &a;
	B* pb = &b;

	pa = dynamic_cast<A*>(pb);
	pa->Show();
	/*���� A �� B �Ŀɷ��ʻ���ʱ���Ž�һ��A*ָ�븳��pa, ���� ����佫��ָ�븳��pa��
	�ò�������;�ǣ�ʹ�ܹ������νṹ�н�������ת����(����is-a��ϵ������������ת���ǰ�ȫ��)
	������������ת����*/
	//pb = dynamic_cast<B*>(pa); // ע������� �˴�������
	//pb->Show();

	const B* pbb = &b;
	B* pbbb = const_cast<B*>(pbb);
	pbbb->ca = 1000;
	pbbb->Show();
    /**pbb��Ϊһ���������޸�b�����ָ�룬��ɾ��const��ǩ*/
	//const A* paa = const_cast<const A*>(pbbb);  // �Ƿ��Ĳ��� ��һ�����͵���һ������

	A* pa1 = static_cast<A*>(&b);
	B* pb1 = static_cast<B*>(&a);
	/*��һ��ת���ǺϷ��� ��Ϊ����ת���������ڵؽ��У��ڶ���ת���Ǵӻ���ָ�뵽������ָ�룬��
	��������������ת��������£����޷����С������������������ת��������Խ�����һ�������
	����ת���� ���ʹ��static_cast����������ת���ǺϷ���
	   ͬ������������м���ת��ö��ֵ�Ϳ���ת��Ϊint ���Կ���static_cast��intת����ö�٣�
    ͬ�� ����ʹ��static_cast��doubleת��Ϊint �� float ת���� double */


	/*reinterpret_cast<type>; ���Խ�ָ��ת��Ϊ���Դ洢ָ���ʾ�������� �����ܽ�ָ��ת��Ϊ��С
	��������������� ��һ�� �ǲ��ܽ�����ָ��ת��Ϊ����ָ��*/

	return 0;
}


//#include <iostream>
//using namespace std;
//
//class A
//{
//public :
//	int m_a;
//
//	A(int a) : m_a(a){}
//
//	virtual void Get(void) const 
//	{
//		cout<< "A...." <<endl;
//	}
//
//	void Show(void)
//	{
//		cout<< "A Show"<<endl;
//	}
//};
//
//class B : public A
//{
//public :
//	int m_b;
//
//	B(int a, int b) : A(a), m_b(b) {}
//
//	virtual void Get(void) const 
//	{
//		cout<< "B...." <<endl;
//	}
//
//	void Show(void)
//	{
//		cout<< "B Show"<<endl;
//	}
//};
//
//int main(void)
//{
//	A* pa = new A(1);
//	A* pb = new B(1,2);
//	pa->Get();
//	pb->Get();
//
//    ((B*)pa)->Show();
//	dynamic_cast<B*>(pa)->Show();
//
//	A* paa = dynamic_cast<A*>(pb);
//	paa->Show();
//	((A*)pb)->Get(); // "B...." �˴����麯���� ���ԲŻ����B���
//	
//
//	return 0;
//}