#include <iostream>
#include <fstream>
using namespace std;

#define ROUTE "D:\\Test.txt"

int main(void)
{
	int x;
	int y;
	int hemo;
	int gate;

	ofstream outFile;
	outFile.open(ROUTE);

	if(!outFile.is_open())
	{
		exit(EXIT_FAILURE);
	}

	cin>>x;
	cin>>y;
	cin>>hemo;
	cin>>gate;

	outFile<<x<<" ";
	outFile<<y<<" ";
	outFile<<hemo<<" ";
	outFile<<gate<<endl;
	outFile.clear();

	x = 0;
	y = 0;
	hemo = 0;
	gate = 0;

	ifstream inFile;
	inFile.open(ROUTE);

	if (!inFile.is_open())
	{
		exit(EXIT_FAILURE);
	}
	// if (inFile.fail())
	// if (inFile.good())
	// if (!inFile)
	
	// ���Ϸ����޷���⵽����һ�����Σ���ͼ�Բ����ʵ��ļ�ģʽ���ļ�ʱ��ʧ��
	// �� is_open() good() �ܼ�⵽���ִ���

	while(inFile.good())  // ��is_ope() �ϵİ屾 
	{
		inFile>>x;
		inFile>>y;
		inFile>>hemo;
		inFile>>gate;
	}
	// eof()  ������һ�ζ�ȡ����ʱ����EOF��eof����true;
	// fail() ����಻ƥ��  fail()����true(�������eof���÷���Ҳ������true)
	// bad()  �ļ������Ӳ������  bad()����true
	// ��Ҫ�ֱ�����Щ���� һ�ָ��򵥵ķ���ʹ��good()���� ��û���κδ����Ƿ���true

	if(inFile.eof() == true)
		cout<<"EOF..."<<endl;
	else if(inFile.fail() == true)
		cout<<"fail..."<<endl;
	else
		cout<<"NO error..."<<endl;

	cout<<x<<endl<<y<<endl<<hemo<<endl<<gate<<endl;

	inFile.clear();
	return 0;
}