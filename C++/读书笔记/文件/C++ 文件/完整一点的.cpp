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
	
	// 以上方法无法检测到这样一种情形：试图以不合适的文件模式打开文件时的失败
	// 但 is_open() good() 能检测到这种错误

	while(inFile.good())  // 是is_ope() 老的板本 
	{
		inFile>>x;
		inFile>>y;
		inFile>>hemo;
		inFile>>gate;
	}
	// eof()  如果最后一次读取数据时遇到EOF，eof返回true;
	// fail() 如果类不匹配  fail()返加true(如果遇到eof，该方法也将返回true)
	// bad()  文件受损或硬件故障  bad()返回true
	// 不要分别检查这些东西 一种更简单的方法使用good()方法 在没有任何错误是返回true

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