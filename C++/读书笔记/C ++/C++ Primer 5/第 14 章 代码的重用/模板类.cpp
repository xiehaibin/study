#include <iostream>
using namespace std;

template <class Type>
class Cbox
{
private :
	int length;
	int width;
	Type arry;

public :
	Cbox(int a, int b);
	void Area(void) const;
};

template<class Type>
Cbox<Type>::Cbox(int a, int b)
{
	length = a;
	width  = b;
}

template<class Type>
void Cbox<Type>::Area(void) const
{
	cout<<"Area: "<< sizeof(arry) <<endl;
}


int main(void)
{
	//Cbox<char*> box(12, 5);
	Cbox<char[40] > box(12, 5);
	box.Area();
	return 0;
}