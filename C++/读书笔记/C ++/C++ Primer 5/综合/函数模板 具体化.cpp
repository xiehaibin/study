// 优先级： 非模板-> 具体化-> 模板
#include <iostream>
#include <cstring>
using namespace std;

struct per
{
	char name[20];
	int  arg;
	float year;
};

template<class T>
void Swap(T &per1, T &per2);

template<>void Swap<per>(per &per1, per &per2);

void Swap(per &per1);

int main(void)
{
	struct per per1 = {"xie hai bin",  24, 5000.0F};
	struct per per2 = {"xie hai bing", 26, 8000.0F};

	cout<<per1.name<<" "<<per1.arg<<" "<<per1.year<<endl;
	cout<<per2.name<<" "<<per2.arg<<" "<<per2.year<<endl
		                                          <<endl;

	Swap(per1.year, per2.year);
	cout<<per1.name<<" "<<per1.arg<<" "<<per1.year<<endl;
	cout<<per2.name<<" "<<per2.arg<<" "<<per2.year<<endl
		                                          <<endl;

	Swap(per1, per2);
	cout<<per1.name<<" "<<per1.arg<<" "<<per1.year<<endl;
	cout<<per2.name<<" "<<per2.arg<<" "<<per2.year<<endl
		                                          <<endl;

	return 0;
}

template<class T>
void Swap(T &y1, T &y2)
{
	T temp = 0.0;
	temp = y1;
	y1 = y2;
	y2 = temp;
}

template<>void Swap<per>(per &per1, per &per2)
{
	char tc[20];
	int ta;
	float ty;

	strcpy(tc,per1.name);
	strcpy(per1.name, per2.name);
	strcpy(per2.name, tc);

	ta = per1.arg;
	per1.arg = per2.arg;
	per2.arg = ta;

	ty = per1.year;
	per1.year = per2.year;
	per2.year = ty;
}

void Swap(per &per)
{
}