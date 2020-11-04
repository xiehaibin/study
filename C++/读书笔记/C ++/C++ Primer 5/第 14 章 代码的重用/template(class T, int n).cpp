#include <iostream>
using namespace std;

template<class Type, int n>
class Arry
{
private :
	Type arry[n];

public :
	explicit Arry();
    virtual Type operator[](int i);  // �˴�������
};


template<class Type, int n>
Arry<Type, n>::Arry(void)
{
	for(int i = 0; i < n; i++)
		cin>>arry[i];
}

template<class Type, int n>
Type Arry<Type, n>::operator [](int i)
{
	if (i<0 || i >= n)
	{
		cout<<"erorr"<<endl;
		exit(0);
	}
	return arry[i];
}

int main(void)
{
	Arry<int, 5> arry;  // ����ڲ��������� ���ͣ� ö�� ���� ָ��   ��Ϊ int i �ǲ��Ϸ� ��int *p �ǺϷ� 
	                    // ģ����벻���޸Ĳ�����ֵ������ ������ n++ , &n �����ı��ʽ�� ���� ��������ڵ�ֵ�����ǳ������ʽ 

	for (int i = 0; i < 5; i++)
		cout<<arry[i];
	return 0;
}