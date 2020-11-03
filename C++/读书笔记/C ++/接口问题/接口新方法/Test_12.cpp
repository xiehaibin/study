#include "test.h"
#include <iostream>
using namespace std;

class A
{
public:

	
	__declspec(noinline) void SetID(int _id) 
	{ 
		id = _id; 
		cout<<"SetID"<<endl;
	}
	__declspec(noinline) int GetID()         
	{ 
		cout<<"GetID"<<endl; 
		return id;  
	}

	__declspec(property(get = GetID, put = SetID)) int iD;

	// __declspec(dllexport) 
	

private:
	int id;
};

#include "ss.h"

int main(void)
{
	A a;

	a.iD = 200;
	cout<<a.iD<<endl;

	cout<<ga<<endl;

	s;
	return 0;
}