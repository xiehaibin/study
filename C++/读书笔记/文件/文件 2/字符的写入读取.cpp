#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream in;

	in.open("d:\\Map\\map_01.txt");

	char ch;

	if (in.is_open())
	{
		while(in.get(ch))
			cout<< ch;
	}
	in.close();

	ofstream out;
    string name;
	out.open("d:\\Test1.txt",ios_base::out | ios_base::app);

	if (!out.is_open())
	{
		cerr<<"reorr...."<<endl;
		exit(1);
	}

	while (getline(cin, name) && name.size() > 0 )
	{
		out<< name <<endl;
	}
	out.close();
	out.clear();

	ifstream it;
	it.open("d:\\Test1.txt");
	
	char ch1;
	if (it.is_open())
	{
		cout<<"µã°É......."<<endl;

		while(it.get(ch))
			cout<< ch;
    
		it.close();
	}
	return 0;
}