#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
#define SIZE 5

int arry[SIZE] = {4,1,2,5,3};

int main(void)
{
	vector<int>va(arry, arry + SIZE), vb(5);
	copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));         // 正向输出
	cout<<endl;

	reverse_copy(va.begin(), va.end(), ostream_iterator<int>(cout, " ")); // 反向输出
	cout<<endl;

	reverse_copy(va.begin(), va.end(), vb.begin());                       // 反向复制给vb
	copy(vb.begin(), vb.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	sort(va.begin(), va.end());                                           // 升幂排序
	copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	sort(vb.begin(), vb.end(), greater<int>());                           // 降幂 #include <functional>
	copy(vb.begin(), vb.end(), ostream_iterator<int>(cout, " "));  
	cout<<endl<<endl;

	va.swap(vb);                                                          // 交换va和vb内容
	copy(va.begin(), va.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	copy(vb.begin(), vb.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	cout<<*find(va.begin(), va.end(),3);                                 // 在va中查找3
	cout<<endl;

	return 0;
}