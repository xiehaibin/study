#include <stack>
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
	stack<int>q; 

	for (int i = 0; i < 3; i++)
	{
		q.push(a[i]);
	}

	cout<< q.size() <<endl;

	while(!q.empty())
	{
		int temp = q.top();
		cout<< temp <<" ";
		q.pop();
	}

	return 0;
}


