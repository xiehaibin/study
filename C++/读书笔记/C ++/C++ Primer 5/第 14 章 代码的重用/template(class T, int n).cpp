#include <iostream>
using namespace std;

template<class Type, int n>
class Arry
{
private :
	Type arry[n];

public :
	explicit Arry();
    virtual Type operator[](int i);  // 此处不明白
};


template<class Type, int n>
Arry<Type, n>::Arry(void)
{
	for(int i = 0; i < n; i++)
		cin>>arry[i];
}

template<class Type, int n>
Type Arry<Type, n>::operator [](int i)
{
	if (i<0 || i >= n)
	{
		cout<<"erorr"<<endl;
		exit(0);
	}
	return arry[i];
}

int main(void)
{
	Arry<int, 5> arry;  // 表达于参数可以是 整型， 枚举 引用 指针   因为 int i 是不合法 但int *p 是合法 
	                    // 模板代码不能修改参数的值，所以 不能有 n++ , &n 这样的表达式， 另外 用作表达于的值必须是常量表达式 

	for (int i = 0; i < 5; i++)
		cout<<arry[i];
	return 0;
}