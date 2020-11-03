#include <iostream>
using namespace std;

class A
{
public  :
	int a;
	int b;

public :
	A(int i = 0, int j = 0)
	{
		a = i;
		b = j;
	}

	void Get(void)
	{
		cout<< a <<endl<< b <<endl;
	}

	A operator+(const A &m) const 
	{
		A t;
		t.a = a + m.a;
		return t;
	}

	A& operator-(void)
	{
		return A(-a, -b);
	}

	friend ostream& operator<<(ostream &os, const A& a);
	friend void     operator>>(istream &is, const A& a);

};

   ostream& operator<<(ostream &os, const A& a)
   {
	   os<< a.a <<" : "<< a.b <<endl;
	   return os;
   }

  void operator>>(istream &is, A& t) 
  {
	  cin >> t.a;
	  cin >> t.b; // 必须得是公有的
  }

int main(void)
{

	int i;
	A a1(2);
	A a2(100, 12);
	A a3(1);

	A a4;
	a4 = a1 + a2 + a3;
	a4.Get();
	cout<<endl;

    cout<<a2<<a1<<a3;

	cout<<endl;
	operator>>(cin, a1);
	a1.Get();

	a2 = -a2;
	a2.Get();



	return 0;
}