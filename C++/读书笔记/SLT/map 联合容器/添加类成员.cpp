#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class A
{
public:
	int x;

	A(int _x){ x = _x; }
};


int main(void)
{
	map<int, A*> m;
	m.insert(map<int, A*>::value_type(1, new A(100)));
	m.insert(map<int, A*>::value_type(2, new A(200)));
	m.insert(map<int, A*>::value_type(3, new A(300)));
	m.insert(map<int, A*>::value_type(3, new A(500)));
	// m[3] = new A(500);

	map<int, A*>::iterator iter = m.find(3);
	if (iter != m.end())
	{
		cout<<(*iter).first<<','<<(*iter).second->x;
	}

	return 0;
}