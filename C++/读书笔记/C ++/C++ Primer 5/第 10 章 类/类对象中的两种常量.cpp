// // 作用域为重个类的 常量
#include <iostream>
using namespace std;

class Enemy
{
private :
	enum en {Len = 10};    // 用这种方法并不创建类的数据成员 所有的对象都不包含枚举 只是一个符号常量 
	//static const int Len = 10; // 该变量和其它静态变量存在一起 而不存储在对象中 所以不占对象的空间
	//int a[Len];	

	// 只有使用这两种技术声明值为整型或枚举的静态常量 而不能存储double 常量
};



int main (void)
{
	Enemy e;

    cout<< sizeof(e) <<endl; // 1

	return 0;
}