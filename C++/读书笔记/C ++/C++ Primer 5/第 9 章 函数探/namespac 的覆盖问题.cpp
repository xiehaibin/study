#include <iostream>
using namespace std;

namespace str
{
	int a = 100;
};

namespace                  // �������Ĵ��� static �ڲ����ӵľ�̬����
{
	int i_static = 4;
}

int m = 100;                // �ⲿ����  �ڱ�İ���ʹ�� ��Ҫ���� extern int m; �����е��ļ���ֻ�ܶ���һ��
static m = 100;             // �ڲ�����
const int m = 100;          // �ڲ��߽�
extern const int m = 100;   // �ⲿ����  �ڱ�İ���ʹ�� ��Ҫ���� extern const int m;

using str::a;               // str�еĽ��ᱻ�ֲ��ĸ���

int main(void)
{
	// using namespace str; // str�еĽ��ᱻ�ֲ��ĸ���
	// using str::a;        // ��������ض���

	int a = 111;

	cout<< a <<endl;
	return 0;
}