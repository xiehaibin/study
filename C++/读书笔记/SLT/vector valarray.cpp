#include <valarray>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

double a[5] = {1, 2, 3, 4, 5};
double b[5] = {10, 20, 30, 40, 50};

void Show(void);

int main(void)
{
	valarray<double>va1(a, 5), va2(b, 5), va3(5), va4(a, 5);
	vector<double>ve1(a, a+5), ve2(b, b+5), ve3(5);

	// �����������е�ֵ��� ��������������
	transform(ve1.begin(), ve1.end(), ve2.begin(), ve3.begin(), plus<double>());
	ostream_iterator<double, char>out(cout, " ");
	copy(ve3.begin(), ve3.end(), out);
	cout<<endl;

	va3 = va1 + va2;
	for (int i = 0; i < (int)va1.size(); i++)
		cout<< va3[i] <<" ";
	cout<<endl;

	// ��va3�е�Ԫ������2.5��
	transform(ve3.begin(), ve3.end(), ve3.begin(), bind1st(multiplies<double>(), 2.5));
	copy(ve3.begin(), ve3.end(), out);
	cout<<endl;

	va3 *= 2.5;
	for (int i = 0; i < (int)va1.size(); i++)
		cout<< va3[i] <<" ";
	cout<<endl;


	// ����������ÿ��Ԫ�ص���Ȼ����
	transform(ve1.begin(), ve1.end(), ve3.begin(), log);
	copy(ve3.begin(), ve3.end(), out);
	cout<<endl;

	va3 = log(va3); // log �������� int ���� 
	for (int i = 0; i < (int)va3.size(); i++)
		cout<< va3[i] <<" ";
	cout<<endl;

	cout<<endl<<endl;

	va4 = va1.apply(log);  // apply ���ı���ö��� ������һ������������¶���
	for (int i = 0; i < (int)va1.size(); i++)
		cout<< va1[i] <<" ";
	cout<<endl;
	for (int i = 0; i < (int)va2.size(); i++)
		cout<< va4[i] <<" ";



	return 0;
}