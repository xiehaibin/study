#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define ROUTE "D:\\Test.txt"

int main(void)
{

	ofstream outFile;
	outFile.open(ROUTE);
	
	if(!outFile.is_open())
		exit(1);

	outFile<<"~~~你以进入了游戏世界~~~"<<endl;
	outFile<<"~~~给你个大名吧...叫天下第一开好了~~~"<<endl;

	outFile.close();
	

	ifstream inFile;
	inFile.open(ROUTE);

	string ch;

	if(!inFile.is_open())
	{
		exit(1);
	}

	while(inFile.good())
	{
		inFile>>ch;
		cout<<ch<<endl;
	}

	if(inFile.eof() == true)
	{
		cout<<"EOF..."<<endl;
	}
	else if(inFile.fail() == true)
	{
		cout<<"fail..."<<endl;
	}
	else if(inFile.bad() == true)
	{
		cout<<"bad..."<<endl;
	}
	else
		cout<<"NO error"<<endl;
	return 0;
}