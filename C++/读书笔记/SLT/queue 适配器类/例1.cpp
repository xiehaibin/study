#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class A
{
public :
	int a;
	A(int i) : a(i) {}
};

int a[3] = {1, 5, 7};

int main(void)
{
	queue<int>q;    // 不能使用 queue<int>q(1, a+3)

	q.push(1);
	q.push(2);

	if (q.empty() == true)
		cout<<"NULL..."<<endl;
	else
		cout<<"ok..."<<endl;

	cout<< q.size() <<endl;

	cout<< q.front() <<endl;

	return 0;
}


