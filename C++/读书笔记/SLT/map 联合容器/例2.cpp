#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	map<char,int,less<char> > map1;
	map<char,int,less<char> >::iterator mapIter;

	//char 是键的类型，int是值的类型
	//下面是初始化，与数组类似
	//也可以用map1.insert(map<char,int,less<char> >::value_type(''c'',3));

	map1['c'] = 3;
	map1['d'] = 4;
	map1['a'] = 1;
	map1['b'] = 2;

	for( mapIter = map1.begin(); mapIter != map1.end(); ++mapIter)
		cout<<" "<< (*mapIter).first
		    <<":"<< (*mapIter).second;
	cout<<endl;

	//first对应定义中的char键，second对应定义中的int值　
	//检索对应于d键的值是这样做的：

	map<char,int,less<char> >::const_iterator ptr;
	ptr = map1.find('d');
	cout<<""<<" "<< (*ptr).first <<"键对应于值："
		         << (*ptr).second <<endl;;
	return 0;
}