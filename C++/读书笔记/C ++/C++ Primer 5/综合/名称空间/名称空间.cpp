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
}

using namespace str; // �����������ƿռ�ĳ�Ա ��Ϊȫ�ֳ�Ա

int main(void)
{
	/*int i_a = 10;
	double fd_d = 20.2;*/

	// using str::i_a  // ���ⵥ����Ա
	// ::������        // ʹ��ȫ�ֵ��������

    Get(i_a, fd_d);
	return 0;
}