//******************************************
//* 名称： 使用time延时                    *  
//* 功能：                                 *
//* 领域：                                 *
//* 时间： 2010.06.22  09：17              *
//******************************************
#include <iostream>
#include <ctime>
using namespace std;

int main(void)
{
	int secs = 0;
	cin>>secs;

   //CLK_TCK   //系统：#define CLK_TCK  CLOCKS_PER_SEC 每秒钟包含的系统时间单位数
   clock_t daly= secs * CLOCKS_PER_SEC; // clock_t系统时间的别名 可以是 unsigned long \ long ...
  // secs / CLOCKS_PER_SEC 将得到秒数
   cout<<"start....."<<endl; 
   cout<< clock() <<endl;
   clock_t start = clock();
   while((clock() - start) < daly);
   cout<<"End......."<<endl;
	return 0;
}