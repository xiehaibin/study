#include <fstream>
#include <iostream>
using namespace std;

#define TEXT "d:\\Test2.txt"

int main(void)
{
	int x = 100;
	int y = 200;
	int hemo = 83;

	int x1 = 0;
	int y1 = 0;
	int hemo1 = 0;
	ofstream ou(TEXT);
	if(!ou)
		cout<<"error..."<<endl;
	ifstream in(TEXT);
	if(!in)
		cout<<"error..."<<endl;

	ou<<x<<endl;
    ou<<y<<endl;
	ou<<hemo<<endl;
    ou.close();

    in>>x1;
	in>>y1;
	in>>hemo1;
	cout<<x1<<endl;
	cout<<y1<<endl;
	cout<<hemo1<<endl;
	in.close();
	return 0;
}