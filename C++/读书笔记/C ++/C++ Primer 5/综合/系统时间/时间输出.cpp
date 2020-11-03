#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main(void)
{
	time_t now = time(0);

	tm* time1 = localtime(&now);

STATE:
	cout<< time1->tm_hour <<endl;
	cout<< time1->tm_sec <<endl;

	return 0;
}