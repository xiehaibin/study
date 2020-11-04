#include <iostream>
#include <stdio.h>
#include <math.h>


using namespace std;

void main(void)
{
//***************** 常用数学函数 *****************
	{
		int i = -123;
		cout<< abs(i) <<endl;       // 整数绝对值  -32768 绝对值是 -32768  

		long il = -12345678L;
		cout<< labs(il) <<endl;     // 长整型绝对值                        

		double id = -123.45;        // 实型绝对值                          *导入 math.h*
		cout<< fabs(id) <<endl;

		cout<< ceil(-10.5) <<endl;  // 大于/等于x的最小整数 = -10          *导入 math.h*
		cout<< ceil(10.9) <<endl;   // = 11

		cout<< floor(-10.5) <<endl; // 小于/等于X的最大整数 =-11
		cout<< floor(10.9) <<endl;  // =10
	}

// ************* 类型转换函数 *******************
	{
	   char ch2[10] = "123.45";
	   cout << atof(ch2) <<endl;     // 将字符串转换成 double             123.45  *不用导入包*
	   cout << atoi(ch2) <<endl;     // 将字符串转换成 int                123     *不用导入包*
	   itoa(int, ch[], 10);          // 将整数转换在字符串
    }

// ************ 字符处理函数 ********************
	{ 
		cout<< isalpha(49) <<endl;   // 判断是否是英文字母 =0                     *不用导入包*
		cout<< isalpha('a') <<endl;  // 结果为非0数                               *不用导入包*

		cout<< islower(97) <<endl;   // 是否是英文小写字母  =结果为非0数          *不用导入包*  
		cout<< islower('A') <<endl;  // =0

		cout<< isupper(97) <<endl;   // 是否是英文大写字母  =0
		cout<< isupper('A') <<endl;  // =结果为非0数  

		cout<< isdigit(49) <<endl;   // 是否是数字字符  =结果为非0数  
		cout<< isdigit('a') <<endl;  // =0

		cout<< tolower(49) <<endl;   // 将大写字母转换成小写字母 =‘49
		cout<< tolower('A') <<endl;  // =97

		cout<< toupper('a') <<endl;  // 将小写字母转换成大写字母 =65
		cout<< toupper(49) <<endl;   // =49

		cout<< toascii(129) <<endl;  // 将字符转换成ASCII代码值  =1
		cout<< toascii('a') <<endl;  // =97

	}
// ************ 字符串处理函数 *********************
	{
	   char a[] = "abcd";
 	   cout<< strupr(a) <<endl;      // 将字符串小写转大写 =ABCD

	   char b[] = "ABCD";
	   cout<< strlwr(b) <<endl;      // 将字符串大写转小写 =abcd
	}

// *********** 其它常用函数 ************************
	{
		
	}
}