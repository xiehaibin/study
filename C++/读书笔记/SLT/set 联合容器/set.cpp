#include <set>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class A
{
public :
	int h;
	A(int a) : h(a) {}
};

int a[4] = {12, 14, 12, 10};
int b[4] = {15, 17, 12, 11};

int main(void)
{
	set<int> a(a, a+4);  // ���ȥ��Ԫ�ػ��Զ�����
	set<int>::iterator is;

	set<int> b(b, b+4);
	set<int> c;

	ostream_iterator<int, char>out(cout," ");
	copy(a.begin(), a.end(), out);             // 10, 12, 114
	cout<<endl;

	for (is = a.begin(); is != a.end(); is++)
		cout<< *is <<" ";
	cout<<endl;

	set_union(a.begin(), a.end(), b.begin(), b.end(), out);  // �����ϲ��������ʾ��
	cout<<endl;

	set_union(a.begin(), a.end(), b.begin(), b.end(), insert_iterator<set<int> >(c, c.begin()));
	// �����ϲ������C
    copy(c.begin(), c.end(), out);

	set_intersection(a.begin(), a.end(), b.begin(), b.end(), out); // ���ҽ���
	cout<<endl;

	set_difference(a.begin(), a.end(), b.begin(), b.end(), out);  // ���Ҳ���
	cout<<endl;

	copy(a.lower_bound(11), a.upper_bound(15), out); 
	// lower_bound(11) ����һ�������� �õ�����ָ�򼯺��е�һ����С�ڹؼ��ֲ����ĳ�Ա
	// upper_bound(15) ����һ�������� �õ�����ָ�򼯺��е�һ�����ڹؼ��ֲ����ĳ�Ա
	cout<<endl;

	return 0;
}