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
	cout<<"������IP��"<<endl;
	cin>>ip;

	out<<"�����Թ�˭����"<<endl;
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

	while(in.get(ch))   // �ڴ˷���
		cout<< ch ;

	in.close();

	return 0;
}