#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
#define SIZE 5

int arry[SIZE] = {4,1,2,5,3};

int main(void)
{
	vector<int>va(arry, arry + SIZE), vb(5);
	copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));         // �������
	cout<<endl;

	reverse_copy(va.begin(), va.end(), ostream_iterator<int>(cout, " ")); // �������
	cout<<endl;

	reverse_copy(va.begin(), va.end(), vb.begin());                       // �����Ƹ�vb
	copy(vb.begin(), vb.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	sort(va.begin(), va.end());                                           // ��������
	copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	sort(vb.begin(), vb.end(), greater<int>());                           // ���� #include <functional>
	copy(vb.begin(), vb.end(), ostream_iterator<int>(cout, " "));  
	cout<<endl<<endl;

	va.swap(vb);                                                          // ����va��vb����
	copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	copy(vb.begin(), vb.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	cout<<*find(va.begin(), va.end(),3);                                 // ��va�в���3
	cout<<endl;

	return 0;
}