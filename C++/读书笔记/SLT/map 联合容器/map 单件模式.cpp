#include <iostream>
#include <map>
using namespace std;

class A
{
public :
	int aa;
	A(int a) 
	{
		aa = a+10;
	}
	A(){}
};

typedef map<int, A*> mapName;
mapName texList;

A* find(int i);
void release(void);

int main(void)
{
	int n;
	A* pa = NULL;
	cout<<"请输入你要查找的数："<<endl;

	while(cin>>n && n > 0)
	{
		pa = find(n);
		cout<<"找到了："<<pa->aa <<endl;
	}

	release();

	cout<< texList.size() <<endl;
	return 0;
}

A* find(int i)
{
	A* pa = NULL;

	mapName::iterator temp = texList.find(i);

	if (temp == texList.end())
	{
		pa = new A(i);
		texList.insert(mapName::value_type(i, pa));
	}


	return pa;
}

void release(void)
{
	mapName::iterator p1 = texList.begin();
	mapName::iterator p2 = texList.end();
	mapName::iterator first1;

	for (first1 = p1; first1 != p2; first1++)
	{
		cout<<"删除："<<(*first1).second->aa<<endl;
		delete (*first1).second;
	}

	texList.clear();
}