#include <vector>
#include <iostream>
using namespace std;

const int SIZE = 7;

int arry[SIZE] = {-1,1,2,3,4,5,-1};

int main(void)
{
	vector<int>av(arry, arry+7);
	typedef vector<int>::iterator iterator;
	iterator first = av.begin()+1;

	for (first; first < av.end()-1; first++)
		cout<< *first <<" ";
	cout<<endl;

	for (--first; first > av.begin(); first--)
		cout<< *first <<" ";
	cout<<endl;

	copy(av.begin()+1, av.end()-1, ostream_iterator<int>(cout, " "));

    cout<<endl;

	typedef vector<int>::reverse_iterator reverse_iterator;
	reverse_iterator last = av.rbegin()+1;

	for (last; last < av.rend()-1; last++)
		cout<< *last <<" ";
	cout<<endl;

	for (--last; last > av.rbegin(); last--)
	{
		cout<< *last <<" ";
	}
	cout<<endl;

	return 0;
}