#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

typedef pair<int, string> Pair;
//typedef map<int, string> Map;
typedef multimap<int, string> Map;  // 可以输出4上个对象

int main(void)
{
	Map codes;
	Map::iterator first;

	codes.insert(Pair(755, "深圳"));
	codes.insert(Pair(755, "东莞"));
	codes.insert(Pair(739, "邵阳"));
	codes.insert(Pair(750, "长沙"));

	first = codes.begin();
	for (first; first != codes.end(); first++)
		cout<< (*first).first <<"  "<< (*first).second <<endl;

	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> rand
		= codes.equal_range(755);

	for (first = rand.first; first != rand.second; first++)
		cout<< (*first).second <<endl;

	return 0;
}