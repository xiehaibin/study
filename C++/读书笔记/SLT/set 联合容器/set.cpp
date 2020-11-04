#include <set>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class A
{
public :
	int h;
	A(int a) : h(a) {}
};

int a[4] = {12, 14, 12, 10};
int b[4] = {15, 17, 12, 11};

int main(void)
{
	set<int> a(a, a+4);  // 存进去的元素会自动排序
	set<int>::iterator is;

	set<int> b(b, b+4);
	set<int> c;

	ostream_iterator<int, char>out(cout," ");
	copy(a.begin(), a.end(), out);             // 10, 12, 114
	cout<<endl;

	for (is = a.begin(); is != a.end(); is++)
		cout<< *is <<" ";
	cout<<endl;

	set_union(a.begin(), a.end(), b.begin(), b.end(), out);  // 两个合并输出到显示器
	cout<<endl;

	set_union(a.begin(), a.end(), b.begin(), b.end(), insert_iterator<set<int> >(c, c.begin()));
	// 两个合并输出到C
    copy(c.begin(), c.end(), out);

	set_intersection(a.begin(), a.end(), b.begin(), b.end(), out); // 查找交集
	cout<<endl;

	set_difference(a.begin(), a.end(), b.begin(), b.end(), out);  // 查找并集
	cout<<endl;

	copy(a.lower_bound(11), a.upper_bound(15), out); 
	// lower_bound(11) 返回一个迭代器 该迭代器指向集合中第一个不小于关键字参数的成员
	// upper_bound(15) 返回一个迭代器 该迭代器指向集合中第一个大于关键字参数的成员
	cout<<endl;

	return 0;
}