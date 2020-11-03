#include <iostream>
using namespace std;
namespace str
{
	int i_a = 1;
	double fd_d = 2.2;
	void Get(double a, double d)
	{
		cout<< (a > d? a : d) <<endl;
	}
	namespace stp  // Ãû³Æ¿Õ¼äµÄÇ¶Ì×
	{
		int i_b = 1000;
		double fd_dd = 1.111;
	}
}

using namespace  str::stp;

int main(void)
{
	cout.setf(ios_base::showpoint);
	cout.precision(6);
	cout<< str::stp::fd_dd <<endl <<endl;
	cout<< i_b <<endl;
	return 0;
}