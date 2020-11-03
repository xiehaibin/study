#include <iostream>
using namespace std;

int main(void)
{
	const int max = 4;
	int a[max];

	for(int i = 0; i < max; i++)
	{
		while(!(cin>>a[i]))        // 如果不时INT类型 将执行后面的
		{
			cin.clear();           // 重置
			while(cin.get()!='\n') // 清除流中的数据
				continue;
		}
	}
	for(int i = 0; i < max; i++)
		cout<< a[i];
	return 0;
}