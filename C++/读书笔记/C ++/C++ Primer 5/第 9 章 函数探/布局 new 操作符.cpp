#include <iostream>
#include <new>
using namespace std;

int main(void)
{
	char ch1[4];

	int *p1 = new (ch1 + 2 * sizeof(int)) int[1];
	int *p2 = new (ch1) int[1];
	int *p3 = new (ch1) int[1];


	cout<< (void*)ch1 <<" : "<< p1 <<endl;  // 0012FEF0
	cout<< (void*)ch1 <<" : "<< p2 <<endl;  // 0012FEE4
	cout<< (void*)ch1 <<" : "<< p3 <<endl;  // 0012FED8

	//delete [] p1;   // error

	return 0;
}