#include <iostream>
using namespace std;

class S
{
private :
	int x;
	int y;

public :
	explicit S(int a) //接受一个参数的构造函数为将类型与该参数相同的值转换为类提供的蓝图
	{                     //有两个参数不能用来转换类型  将构造函数用做自动类型转换函数似乎是一项
		x = a;            //不错的特性。  C++新增了一个关键字 explicit 用来关闭这种自动特性
	}

	S(){}

	S(int a, int b)
	{
		x = a;
		y = b;
	}

	void Get(void)
	{
		cout<<"x: "<<x<<endl;
	}

	operator int() const
	{
		return x; //*this 是不行的
	}
};

int main(void)
{

	S a;
	//a = 10;  //  用explicit关闭了隐式转换

	a = S(90);
	a = (S)100;
	//a.Get();
	// 只接受一个参数的构造函数定义了从参数类型到类类型的转换。如果使用关键字explicit限定了这种构造
	// 函数，则只能用于显于转换， 否则也可以用于隐式转换


	// 构造函数只用于从某种类型到类类型的转，要进行相反的转换必须用特殊的C++操作符函数 -- 转换函数
	// int b = (int)a;
	// int n = int(a);
    // 编绎器发现 右侧是 S 类型 而左侧是 DOUBLE 类型 因此它将查看程序员是否定义了与此匹配的转换函数
	// （没有的话 将生成错误）


	// 创建转换函数的方法 operator typeName ()
	// 1. 转换函数必须是类方法
	// 2. 转换函数不能指定返回值
	// 3. 转换函数不能有参数
	cout<<"int(a): "<<int(a) <<endl;

    S f(100, 200);

	return 0;
}