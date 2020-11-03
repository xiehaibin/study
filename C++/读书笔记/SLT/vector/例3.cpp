#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class Eenmy
{
	int hp;
};

int main(void)
{
	int b[5] = {1,2,3,4,5};
	int a[5] = {6,7,8,9,10};
	vector<int>va(a, a+5);
	vector<int>vb(b, b+5);
 
    copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));  // 直接构造一个匿名迭代器
	cout<<endl;

	//ostream_iterator<int>out_iter(cout, " ");                    // 这是老式的C++实现
	ostream_iterator<int, char>out_iter(cout, " ");
	copy(va.begin(), va.end(), out_iter);
	cout<<endl;

	//copy(istream_iterator<int, char>(cin), istream_iterator<int, char>(), vb.begin());
	//copy(vb.begin(), vb.end(), ostream_iterator<int>(cout, " "));

	copy(va.rbegin(), va.rend(), out_iter);   // 反向输出
	cout<<endl;
	vector<int>::reverse_iterator ri;
	for(ri = va.rbegin(); ri != va.rend(); ri++)
		cout<< *ri  <<" ";
	cout<<endl;

    back_insert_iterator<vector<int> > back_iter(vb);
	copy(va.begin(), va.end(), back_iter); // 将元素插入到容器的尾部
	copy(vb.begin(), vb.end(), out_iter);
	cout<<endl<<endl;

    // copy(va.begin(), va.end(), front_insert_iterator<vector<int> >(vb)); // 将元素插入到容器的前端
	// copy(vb.begin(), vb.end(), out_iter);       // vector 不能满足这种要求 但queue满足

	copy(va.begin(), va.end(), insert_iterator<vector<int> >(vb, vb.begin()));  // 没有容器类型的限制
	copy(vb.begin(), vb.end(), out_iter);  // vb.begin() 是要插入的位置

	// 上述的三上个方法必须声明容器类型的原因是：迭代器必须使用合适的容器方法
    // back_insert_iterator 的构造函数将假设传递给它的类型有一个 push_back()方法。copy()是一个
	// 独立的函，没有重新调整容器大小的权限。但前面的声明让back_iter能够使用方法 
	// vector<int>::push_back, 该方法有这样的权限





	return 0;
}