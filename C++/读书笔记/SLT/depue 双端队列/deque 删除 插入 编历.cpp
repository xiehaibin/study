#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int a[5] = {1,2,3,4,5};

int main(void)
{
	deque<int>q2(a, a+5);

	deque<int>::iterator first;
	first = q2.begin();


	for (first; first != q2.end(); first++)
		cout<< *(first) <<" ";

	cout<<endl<<endl;

	q2.pop_back();
	q2.pop_front();
	q2.erase(q2.begin()+2);

	q2.push_front(100);
	q2.push_back(122);

	ostream_iterator<int, char>out_iter(cout, " ");
	copy(q2.begin(), q2.end(), out_iter);
}

