#include <iostream>
using namespace std;

class Queue
{
public :
	struct link
	{
		int data;
		link* next;
	}; // �����������Ľṹ �� ö�ٳ�Ϊ��Ƕ�������У������������ᴴ�����ݶ��� ��ֻ��ָ�ڿ���������
	   // ʹ������  �����˽�в�ֻ�ܱ������ʹ�� ������ڹ��в��ֽ��е� ����ʹ�����������������ʹ
	   // ������������ 

	const int MAX;
	int & length;

public :
	Queue(int a, int & b) : MAX(a), length(b)
	{
	   // �Ǿ�̬consr���Ա �������Ա const���Ա ����ʹ�ò����б���г�ʼ��
	   // ���ݱ�������xuen�������ǳ������������е�xuen����ͬ ������б��޹�
	}
private : // ���˼��ַ�������˽�в��ֵĺô�
	Queue(const Queue & q);
	Queue operator=(const Queue & Q);
	// 1.��������Ĭ�ϵķ������� 2. ��Ϊ������˽�е� ��˷����ܱ��㷴ʹ��  n v ��Queue�Ķ���
	// Queue q(v) v = n ������������������

	void Get(void) const
	{
		cout<< MAX <<endl;
		cout<< length <<endl;
	}
};

int main(void)
{
	int a = 100;
	int b = 200;

	Queue queue(a, b);
	queue.Get();

	//cout<< sizeof(queue) <<endl;

	Queue::link lk;
	return 0;
}