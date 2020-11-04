#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class Eenmy
{
	int hp;
};

int main(void)
{
	int b[5] = {1,2,3,4,5};
	int a[5] = {6,7,8,9,10};
	vector<int>va(a, a+5);
	vector<int>vb(b, b+5);
 
    copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));  // ֱ�ӹ���һ������������
	cout<<endl;

	//ostream_iterator<int>out_iter(cout, " ");                    // ������ʽ��C++ʵ��
	ostream_iterator<int, char>out_iter(cout, " ");
	copy(va.begin(), va.end(), out_iter);
	cout<<endl;

	//copy(istream_iterator<int, char>(cin), istream_iterator<int, char>(), vb.begin());
	//copy(vb.begin(), vb.end(), ostream_iterator<int>(cout, " "));

	copy(va.rbegin(), va.rend(), out_iter);   // �������
	cout<<endl;
	vector<int>::reverse_iterator ri;
	for(ri = va.rbegin(); ri != va.rend(); ri++)
		cout<< *ri  <<" ";
	cout<<endl;

    back_insert_iterator<vector<int> > back_iter(vb);
	copy(va.begin(), va.end(), back_iter); // ��Ԫ�ز��뵽������β��
	copy(vb.begin(), vb.end(), out_iter);
	cout<<endl<<endl;

    // copy(va.begin(), va.end(), front_insert_iterator<vector<int> >(vb)); // ��Ԫ�ز��뵽������ǰ��
	// copy(vb.begin(), vb.end(), out_iter);       // vector ������������Ҫ�� ��queue����

	copy(va.begin(), va.end(), insert_iterator<vector<int> >(vb, vb.begin()));  // û���������͵�����
	copy(vb.begin(), vb.end(), out_iter);  // vb.begin() ��Ҫ�����λ��

	// ���������ϸ��������������������͵�ԭ���ǣ�����������ʹ�ú��ʵ���������
    // back_insert_iterator �Ĺ��캯�������贫�ݸ�����������һ�� push_back()������copy()��һ��
	// �����ĺ���û�����µ���������С��Ȩ�ޡ���ǰ���������back_iter�ܹ�ʹ�÷��� 
	// vector<int>::push_back, �÷�����������Ȩ��





	return 0;
}