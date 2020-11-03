#include <iostream>
using namespace std;

template<class Type>
class A
{
//private :
public :
	Type ca;

	class B  // struct B  �������ͬ �����ǽ��������Ϊ��һ��ĳ�Ա�� ��Ƕ���ǲ�������ĳ�Ա ���Ƕ���һ������
	{
	public :
		Type cb;

		B(Type b) : cb(b)
		{
			cout<< "B..." <<endl;
		}

		void Show(void) const
		{
			cout<< cb <<endl;
		}
	};

	B* pb;

public :
	A(Type a, Type b) : ca(a)
	{
		pb = new B(b);
		cout<< "A..." <<endl;
	}

	void Show(void);

	~A(void);
};

template<class Type>
A<Type>::~A(void)
{
	delete pb;
}

template<class Type>
void A<Type>::Show(void)
{
	cout<<"A: "<< ca <<endl
		<<"B: "<< pb->cb <<endl;
}

//template<class Type>
//A<Type>::B::B(Type b) : cb(b)
//{
//	cout<< "B..." <<endl;
//}


int main(void)
{
	A<int> a(1, 2);

	a.Show();

	A<int>::B b(12);
	b.Show();
	return 0;
}