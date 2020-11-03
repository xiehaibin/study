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
	/*仅当 A 是 B 的可访问基类时，才将一个A*指针赋给pa, 否则 该语句将空指针赋给pa；
	该操作的用途是，使能够在类层次结构中进行向上转换，(由于is-a关系，这样的类型转换是安全的)
	而不允许其它转换。*/
	//pb = dynamic_cast<B*>(pa); // 注释上面的 此处将出错
	//pb->Show();

	const B* pbb = &b;
	B* pbbb = const_cast<B*>(pbb);
	pbbb->ca = 1000;
	pbbb->Show();
    /**pbb成为一个可用于修改b对象的指针，它删除const标签*/
	//const A* paa = const_cast<const A*>(pbbb);  // 非法的操作 从一种类型到另一种类型

	A* pa1 = static_cast<A*>(&b);
	B* pb1 = static_cast<B*>(&a);
	/*第一种转换是合法的 因为向上转换可以显于地进行，第二种转换是从基类指针到派生类指针，在
	不进行显于类型转换的情况下，将无法进行。但由于无须进行类型转换，便可以进行另一个方向的
	类型转换， 因此使用static_cast来进行向下转换是合法的
	   同理，由于无须进行尖型转，枚举值就可以转换为int 所以可用static_cast将int转换成枚举，
    同样 可以使用static_cast将double转换为int 将 float 转换成 double */


	/*reinterpret_cast<type>; 可以将指针转换为足以存储指针表示的整数， 但不能将指针转换为更小
	的整数或符点数， 另一个 是不能将函数指针转换为数据指针*/

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
//	((A*)pb)->Get(); // "B...." 此处有虚函数在 所以才会调用B类的
//	
//
//	return 0;
//}