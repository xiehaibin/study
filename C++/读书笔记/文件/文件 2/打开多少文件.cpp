#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	string str[3] =
	{
		"d:\\Test1.txt",
		"d:\\Test2.txt",
		"d:\\Test3.txt"
	};

	ifstream in;

	int sum = 0;
	int temp = 0;
	
	for (int i = 0; i < 3; i++)
	{
		in.open(str[i].c_str());  //ʹ��c_str()�������캯���ṩһ��C�����ַ�������

		if (!in.is_open())
		{
			cerr<<"error..."<<endl;
			exit(1);
		}
        
		in>>temp;
		sum += temp;

		in.clear();
		in.close();
	}

	cout<< sum / 3 <<endl;
	return 0;
}