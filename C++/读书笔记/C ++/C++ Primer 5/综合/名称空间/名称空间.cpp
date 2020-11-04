#include <iostream>
using namespace std;
namespace str
{
	int i_a = 1;
	double fd_d = 2.2;
	void Get(double a, double d)
	{
		cout<< (a > d? a : d) <<endl;
	}
}

using namespace str; // 暴光所有名称空间的成员 成为全局成员

int main(void)
{
	/*int i_a = 10;
	double fd_d = 20.2;*/

	// using str::i_a  // 暴光单个成员
	// ::变量名        // 使用全局的这个变量

    Get(i_a, fd_d);
	return 0;
}