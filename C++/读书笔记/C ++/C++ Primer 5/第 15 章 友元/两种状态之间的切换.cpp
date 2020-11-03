#include <iostream>
using namespace std;

void key_1(void)
{
	enum{OFF, ON};

	int key = ON;
	int n = 0;

Start:
	key = (key == ON)? OFF : ON;
	n++;
	if (key == ON)
		cout<<" ON "<<endl;
	else
		cout<<" OFF "<<endl;

	if (n < 10)
		goto Start;
	cout<<endl<<endl;
}

void key_2(void)
{
	int key = 1;
	int n = 0;

Start:
	key^= 1;
	n++;
	if (key == 1)
		cout<<" ON "<<endl;
	else
		cout<<" OFF "<<endl;
	if (n < 10)
		goto Start;
}

int main(void)
{
	key_1();
	key_2();
	return 0;
}