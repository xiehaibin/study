//******************************************
//* 名称： 格式化输出                      *  
//* 功能：                                 *
//* 领域：                                 *
//* 来源： primer 5  239页                 *
//* 时间： 2010.06.22  09：17              *
//******************************************
#include <iostream>
using namespace std;
int main(void)
{
	double d = 1.1111;
	int a = 100;

	ios_base::fmtflags inital; //返回调用它之前有效的所有格式化设置 ios_base::fmtflags
	                           //是存取这种信息的数据类型名称
	inital = cout.setf(ios_base::showpoint);

	//cout.precision(0);             // 指定显于多少位小数
	cout<<"xie hai bin"<<endl;
	cout.setf(ios_base::fixed);      // 将对象设置小数点显于模式
	cout.precision(2);
	cout<< d <<endl;
	cout.width(10);                  // 设置一下下一次输出操做使用的字断宽度
	cout<< a <<endl;
	cout<< a <<endl<<endl;

	cout.setf(inital);              // 将所有的格式化设置恢复原来值。          
	cout<< d <<endl;
	cout<< a <<endl;
	return 0;
}