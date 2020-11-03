#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	string name;

	ofstream out;
	out.open("d:\\Test.txt");
	
	if (!out.is_open())
	{
		cerr<<"error..."<<endl;
		exit(EXIT_FAILURE);
	}

	float ip = 0.0;
	cout<<"请输入IP："<<endl;
	cin>>ip;

	out<<"人生自古谁无死"<<endl;
	out<<"IP: "<< ip <<endl;

	out.close();

	ifstream in;
	in.open("d:\\Test.txt");

	if (!in.is_open())
	{
		cerr<<"error..."<<endl;
		exit(1);
	}

    char ch;

	while(in.get(ch))   // 在此方法
		cout<< ch ;

	in.close();

	return 0;
}