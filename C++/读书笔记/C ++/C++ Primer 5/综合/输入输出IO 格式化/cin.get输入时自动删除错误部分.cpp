#include <iostream>
using namespace std;

int main(void)
{
	const int max = 4;
	int a[max];

	for(int i = 0; i < max; i++)
	{
		while(!(cin>>a[i]))        // �����ʱINT���� ��ִ�к����
		{
			cin.clear();           // ����
			while(cin.get()!='\n') // ������е�����
				continue;
		}
	}
	for(int i = 0; i < max; i++)
		cout<< a[i];
	return 0;
}