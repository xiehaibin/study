#include <list>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

template<class T>
class CFind
{
public:
	T tem;
	CFind(const T & t) : tem(t) {}
	bool operator()(const T & v);
};

int a[5] = {4, 1, 3,1,1};

void Show(int & pa);
bool find_z(int a);

int main(void)
{
	list<int>ls1;
	list<int>ls2(a, a+5);
	list<int>::iterator first;
	ls1.insert(ls1.begin(), ls2.begin(), ls2.end());
	first = ls2.begin();

	ls2.erase(first);   //  删除
	for_each(ls2.begin(), ls2.end(), Show);
	cout<<endl<<endl;

	//ls1.remove(1);  // 是否能用于自定义类型 ??
	//ls1.remove_if(find_z);
	ls1.remove_if(CFind<int>(3));  // 删除大于3的元素
	//CFind<int>f100(3);
	//ls1.remove_if(f100);

	cout<<"remove_if........"<<endl;
	for_each(ls1.begin(), ls1.end(), Show);
	cout<<endl<<endl;

	ls1.splice(ls1.begin(), ls2);
	ls1.sort();  // 不能使用非成员的 sort
	for_each(ls1.begin(), ls1.end(), Show);
	cout<<endl;

	ls1.unique();  // 只将相邻的相同值压缩为单个值 并将删除重复的值
	for_each(ls1.begin(), ls1.end(), Show);

	cout<< ls1.size() <<endl;


	return 0;
}

void Show(int & pa)
{
	cout<<"A: "<< pa <<" ";
}

bool find_z(int a)
{
	return a > 2;
}

template<class T>
bool CFind<T>::operator()(const T & v)
{
	return v > tem;
}

