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

	sort(vc.begin(), vc.end());    // 调用operator< 全排序  
	for_each(vc.begin(), vc.end(),  ShowReview);
	cout<<endl<<endl;

	random_shuffle(vc.begin(), vc.end());

	sort(vc.begin(), vc.end(), Swap); // 对Crad对象的排序是完整弱排序的
    for_each(vc.begin(), vc.end(),  ShowReview);
	cout<<endl<<endl;

	//  a < b  b<a 都不成立 则a 和 b 必定相同， 在完整弱排序中 情况不是这样的了 它们可能相同
	//  也可能只在么方面相同
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
		return false; // 表示两个对象的顺序不正确
}

void ShowReview(const Crad & crad)
{
	cout<<"ho: "<< crad.ho <<"  "<<"daxi: "<< crad.daxi <<endl;
}


