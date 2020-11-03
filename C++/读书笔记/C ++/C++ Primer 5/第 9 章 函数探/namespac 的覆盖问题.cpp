#include <iostream>
using namespace std;

namespace str
{
	int a = 100;
};

namespace                  // 用无名的带替 static 内部连接的静态变量
{
	int i_static = 4;
}

int m = 100;                // 外部连接  在别的包中使用 需要声明 extern int m; 在所有的文件中只能定义一次
static m = 100;             // 内部连接
const int m = 100;          // 内部边接
extern const int m = 100;   // 外部连接  在别的包中使用 需要声明 extern const int m;

using str::a;               // str中的将会被局部的覆盖

int main(void)
{
	// using namespace str; // str中的将会被局部的覆盖
	// using str::a;        // 将会产生重定义

	int a = 111;

	cout<< a <<endl;
	return 0;
}