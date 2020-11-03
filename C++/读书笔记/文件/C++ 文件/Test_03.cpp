#include <iostream>
#include <fstream>
using namespace std;
#define TEXT "d:\\Test03.txt"
#define STRING "游戏研发中..."

int main(void)
{
	ofstream out(TEXT);
	if(!out)
	{
		cout<<"ou error..."<<endl;
		return 1;
	}
	int d = 36;
	//char str[] = STRING;
	int x = 100;
	int y = 230;
	//out.write(str, static_cast<int>(strlen(str)));
	out.write((char*)&d, sizeof(double));
	out.write((char*)&x, sizeof(double));
	out.write((char*)&y, sizeof(double));
	out.close();

    ifstream in(TEXT);
	if(!in)
	{
		cout<<"in error..."<<endl;
		return 1;
	}
	int d1 = 0;
	int x1 = 0;
	int y1 = 0;
	//in.read(str, static_cast<int>(strlen(str)));
	in.read((char*)&d1, sizeof(double));
	in.read((char*)&x1, sizeof(double));
	in.read((char*)&y1, sizeof(double));

	//cout<<str<<endl;
	cout<<d1<<endl;
	cout<<x1<<endl;
	cout<<y1<<endl;
	in.close();
}