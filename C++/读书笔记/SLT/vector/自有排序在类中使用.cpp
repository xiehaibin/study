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
	Crad(){}
};

bool Swap(const Crad & crad1, const Crad & crad2)  // 必须是全局的才行
{
	if (crad1.ho < crad2.ho)
		return true;
	else
		return false;
}


class A
{

public :
	static const int size = 3;
	Crad pc[size];

	vector<Crad>vc;
	typedef vector<Crad>::iterator iterator;

	A(void)
	{
		pc[0] = Crad(3,4);
		pc[1] = Crad(2,1);
		pc[2] = Crad(1,6);

		vc.push_back(pc[0]);
		vc.push_back(pc[1]);
		vc.push_back(pc[2]);
	}

	/*static bool Swap(const Crad & crad1, const Crad & crad2)
	{
		if (crad1.ho < crad2.ho)
			return true;
		else
			return false;
	}*/

	void Suff()
	{
		sort(vc.begin(), vc.end(), Swap);
	}


	void Get(void)
	{
		//iterator first = vc.begin();
		//iterator first2;

		//for (iterator first = vc.begin(); first != vc.end()-1; first++)
		//{
		//	for (iterator first2 = first+1; first2 != vc.end(); first2++)
		//	{
		//		if (first->ho > first2->ho)
		//		{
		//			iterator::value_type temp;

		//			temp = *first;
		//			*first = *first2;
		//			*first2 = temp;
		//		}
		//	}
		//}

		/*for (int i = 0; i < 3-1; i++)
		{
			for (int j = i+1; j < 3; j++)
			{
				if (vc[i].ho > vc[j].ho)
				{
					iterator::value_type temp;

					temp = vc[i];
					vc[i] = vc[j];
					vc[j] = temp;
				}
			}
		}*/

		for (iterator first = vc.begin(); first != vc.end(); first++)
		{
			cout<< (*first).ho <<endl;
		}
	}
};

int main(void)
{
	A a;
	a.Suff();
	a.Get();

	return 0;
}




//
//#include <iostream>
//using namespace std;
//
//int main(void)
//{
//	int a[5] = {3,2,5,4,1};
//
//	for (int i = 0; i < 5-1; i++)
//	{
//		for (int j = i+1; j < 5; j++)
//		{
//			if (a[i] > a[j])
//			{
//				int temp = 0;
//
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//
//
//	for (int i = 0; i < 5; i++)
//		cout<< a[i] <<" ";
//	return 0;
//}