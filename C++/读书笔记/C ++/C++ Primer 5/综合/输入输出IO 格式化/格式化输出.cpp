//******************************************
//* ���ƣ� ��ʽ�����                      *  
//* ���ܣ�                                 *
//* ����                                 *
//* ��Դ�� primer 5  239ҳ                 *
//* ʱ�䣺 2010.06.22  09��17              *
//******************************************
#include <iostream>
using namespace std;
int main(void)
{
	double d = 1.1111;
	int a = 100;

	ios_base::fmtflags inital; //���ص�����֮ǰ��Ч�����и�ʽ������ ios_base::fmtflags
	                           //�Ǵ�ȡ������Ϣ��������������
	inital = cout.setf(ios_base::showpoint);

	//cout.precision(0);             // ָ�����ڶ���λС��
	cout<<"xie hai bin"<<endl;
	cout.setf(ios_base::fixed);      // ����������С��������ģʽ
	cout.precision(2);
	cout<< d <<endl;
	cout.width(10);                  // ����һ����һ���������ʹ�õ��ֶϿ��
	cout<< a <<endl;
	cout<< a <<endl<<endl;

	cout.setf(inital);              // �����еĸ�ʽ�����ûָ�ԭ��ֵ��          
	cout<< d <<endl;
	cout<< a <<endl;
	return 0;
}