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
		cout<<"Ԫ�ظ�����"<<static_cast<int>(vint.size())<<endl;
		cout<<"��������Ҫɾ����ֵ��";
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
			cout<<"ɾ����ֵΪ "<< n <<" ��Ԫ��"<<endl;
			first = vint.erase(first);
			break;
		}
		else
		{
			first++;
			cout<<"û��Ϊ "<< n <<" ֵ"<<endl;
			continue;
		}
	}

	cout<<"����Ԫ�ظ�����"<<static_cast<int>(vint.size())<<endl;

	cout<<endl;
//	copy(vint.begin(), vint.end(), out);
	cout<<endl;

}