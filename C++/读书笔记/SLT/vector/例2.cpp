#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

#define SIZE 5

class Crad
{
public :
	int ho;
	int daxi;

public :
	Crad(int a, int b) : ho(a), daxi(b) {}
};

void ShowReview(const Crad & crad);
bool operator<(const Crad & crad1, const Crad & crad2);
bool Swap(const Crad & crad1, const Crad & crad2);

int main(void)
{
	Crad pc[5] = { Crad(1,4), Crad(2,6), Crad(3,9), Crad(4,2), Crad(5,10)};
	vector<Crad>vc(pc, pc+5);
	typedef vector<Crad>::iterator iterator;

	random_shuffle(vc.begin(), vc.end());
    for_each(vc.begin(), vc.end(),  ShowReview);
	cout<<endl<<endl;

	sort(vc.begin(), vc.end());    // ����operator< ȫ����  
	for_each(vc.begin(), vc.end(),  ShowReview);
	cout<<endl<<endl;

	random_shuffle(vc.begin(), vc.end());

	sort(vc.begin(), vc.end(), Swap); // ��Crad����������������������
    for_each(vc.begin(), vc.end(),  ShowReview);
	cout<<endl<<endl;

	//  a < b  b<a �������� ��a �� b �ض���ͬ�� �������������� ��������������� ���ǿ�����ͬ
	//  Ҳ����ֻ��ô������ͬ
	return 0;
}

bool Swap(const Crad & crad1, const Crad & crad2)
{
	if (crad1.ho < crad2.ho)
		return true;
	else
		return false;
}

bool operator<(const Crad & crad1, const Crad & crad2)
{
	if (crad1.daxi < crad2.daxi)
		return true;
	else if ((crad1.daxi == crad2.daxi) && (crad1.ho < crad2.ho))
		return true;
	else
		return false; // ��ʾ���������˳����ȷ
}

void ShowReview(const Crad & crad)
{
	cout<<"ho: "<< crad.ho <<"  "<<"daxi: "<< crad.daxi <<endl;
}


