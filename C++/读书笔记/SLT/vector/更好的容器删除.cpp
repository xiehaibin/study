#include <vector> 
#include <iostream>
using namespace std;

vector<int>vint;
//ostream_iterator<int>out(cout," ");
vector<int>::iterator first;
vector<int>::iterator first2;

void deleteFun(const int n);

int main(void)
{

	vint.push_back(10);
	//vint.push_back(11);
	//vint.push_back(12);
	//vint.push_back(13);

//	copy(vint.begin(), vint.end(), out);
	cout<<endl;

	printf("%d\n", vint.end());
	printf("%d\n", vint.begin());

	int temp = 0;
	for (first2 = vint.begin(); first2 < vint.end();)
	{
		cout<<"元素个数："<<static_cast<int>(vint.size())<<endl;
		cout<<"请输入你要删除的值：";
		cin>>temp;
		cout<<endl;

		deleteFun(temp);

		first2 = vint.begin();

	}
	return 0;
}

void deleteFun(const int n)
{
	for (first = vint.begin(); first != vint.end();)
	{
		if (n == *first)
		{
			cout<<"删除了值为 "<< n <<" 的元素"<<endl;
			first = vint.erase(first);
			break;
		}
		else
		{
			first++;
			cout<<"没有为 "<< n <<" 值"<<endl;
			continue;
		}
	}

	cout<<"容器元素个数："<<static_cast<int>(vint.size())<<endl;

	cout<<endl;
//	copy(vint.begin(), vint.end(), out);
	cout<<endl;

}