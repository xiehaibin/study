// // ������Ϊ�ظ���� ����
#include <iostream>
using namespace std;

class Enemy
{
private :
	enum en {Len = 10};    // �����ַ�����������������ݳ�Ա ���еĶ��󶼲�����ö�� ֻ��һ�����ų��� 
	//static const int Len = 10; // �ñ�����������̬��������һ�� �����洢�ڶ����� ���Բ�ռ����Ŀռ�
	//int a[Len];	

	// ֻ��ʹ�������ּ�������ֵΪ���ͻ�ö�ٵľ�̬���� �����ܴ洢double ����
};



int main (void)
{
	Enemy e;

    cout<< sizeof(e) <<endl; // 1

	return 0;
}