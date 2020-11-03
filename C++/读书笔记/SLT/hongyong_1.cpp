#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int a[5] = {1,2,3,4,5};
int b[5] = {10, 20, 30, 40, 50};

int sqrt(int & a);

int main(void)
{
	vector<int>va(a,a+5);
	vector<int>vb(b,b+5);


	ostream_iterator<int, char>out(cout, " ");
	copy(va.begin(), va.end(), out);  
	cout<<endl;
	copy(vb.begin(), vb.end(), out);  
	cout<<endl;

	transform(va.begin(), va.end(),/* vb.begin(),*/ out, sqrt); 
	cout<<"sprt"<<endl;

	transform(va.begin(), va.end(), vb.begin(), vb.begin(), plus<int>());// 将两个容器中的元素相加 
	copy(vb.begin(), vb.end(), out);  
	cout<<endl;
   
	transform( va.begin(), va.end(), out, bind1st(multiplies<int>(), 100) ); 
	//bind1st(multiplies<int>(), 100) 是一个配适器函数 将二元函数  转换为一元函数 

	return 0;
}

int sqrt(int & a)
{
	return a*a;
}