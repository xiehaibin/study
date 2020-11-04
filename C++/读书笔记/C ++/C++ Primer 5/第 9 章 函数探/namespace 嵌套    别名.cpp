#include <iostream>
using namespace std;

namespace str
{
	int a = 10;

	namespace sb
	{
		int b = 11;
	}

	void fun(int a)
	{
		cout<<"int a" <<endl;
	}

	void fun(double d)
	{
		cout<<"double d"<<endl;
	}
}

// using namespace str::sb;  // 使用 using编绎指令使用内部名称

// namespace type = str;  *
 
//namespace typespace = str::sb; &

int main(void)
{
	// using namespace type; *
	// cout<< a <<endl;      *

   /* using namespace typespace;  &
	cout<< b <<endl;*/       //   &


	using str::fun;
 // 如果重载将导入所有的版本
	fun(1); 
	fun(1.0);

	return 0;
}