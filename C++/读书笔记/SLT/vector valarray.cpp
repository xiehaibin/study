#include <valarray>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

double a[5] = {1, 2, 3, 4, 5};
double b[5] = {10, 20, 30, 40, 50};

void Show(void);

int main(void)
{
	valarray<double>va1(a, 5), va2(b, 5), va3(5), va4(a, 5);
	vector<double>ve1(a, a+5), ve2(b, b+5), ve3(5);

	// 将两个容器中的值相加 赋给第三个容器
	transform(ve1.begin(), ve1.end(), ve2.begin(), ve3.begin(), plus<double>());
	ostream_iterator<double, char>out(cout, " ");
	copy(ve3.begin(), ve3.end(), out);
	cout<<endl;

	va3 = va1 + va2;
	for (int i = 0; i < (int)va1.size(); i++)
		cout<< va3[i] <<" ";
	cout<<endl;

	// 将va3中的元素扩大2.5陪
	transform(ve3.begin(), ve3.end(), ve3.begin(), bind1st(multiplies<double>(), 2.5));
	copy(ve3.begin(), ve3.end(), out);
	cout<<endl;

	va3 *= 2.5;
	for (int i = 0; i < (int)va1.size(); i++)
		cout<< va3[i] <<" ";
	cout<<endl;


	// 计算容器中每个元素的自然对象
	transform(ve1.begin(), ve1.end(), ve3.begin(), log);
	copy(ve3.begin(), ve3.end(), out);
	cout<<endl;

	va3 = log(va3); // log 不能用于 int 类型 
	for (int i = 0; i < (int)va3.size(); i++)
		cout<< va3[i] <<" ";
	cout<<endl;

	cout<<endl<<endl;

	va4 = va1.apply(log);  // apply 不改变调用对象 但返回一个包含结果的新对象
	for (int i = 0; i < (int)va1.size(); i++)
		cout<< va1[i] <<" ";
	cout<<endl;
	for (int i = 0; i < (int)va2.size(); i++)
		cout<< va4[i] <<" ";



	return 0;
}