#include <fstream>
#include <iostream>
using namespace std;

int main(void)
{
	char p[16];
	ofstream out("d:\\Test.txt");
	ifstream in("d:\\Test.txt");
	out<<"ÓÎÏ·±£´æÖÐ...";
    out.close();

	in>>p;
	cout<<p<<endl;
	return 0;
}