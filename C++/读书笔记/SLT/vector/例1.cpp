#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

#define SIZE 5

void ShowReview(int a);

int main(void)
{
	int a[SIZE] = {1,2,3,4,5};
	int b[SIZE] = {10,20,30,40,50};

	vector<int>vc(a, a+SIZE);
	vector<int>vb(b, b+SIZE);

	typedef vector<int>::iterator iterator;
	iterator first = vc.begin();

	vc.swap(vb);
	vc.erase(vc.begin(), vc.begin()+2);
	vc.insert(vc.begin(), vb.begin()+1, vb.end());

	for_each(vc.begin(), vc.end(), ShowReview); // 使用此函数来输出ShowReview 用户类型输出很有用
	random_shuffle(vc.begin(), vc.end());



	for(int i = 0; i < (int)vc.size(); i++)
		//cout<< vc[i] <<" ";   // 因为操作符[]被重载 所以才能以数组表于法来访问
	cout<<endl;

	int arry[5] = {1,2,3,4,5};
	random_shuffle(arry, arry+5);
	for (int i = 0; i < 5; i++)
		//cout<< arry[i] <<" ";

	return 0;
}

void ShowReview(int a)
{
	cout<<"A: "<< a <<endl;
}

