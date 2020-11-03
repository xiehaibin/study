#include <valarray>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

double a[5] = {3, 1, 2, 5, 4};

int main(void)
{
	// valarray 使用STL中的函数
	/*valarray<double>ve(a, 5);
	ostream_iterator<double, char>out(cout, " ");
	sort(&ve[0], &ve[5]);
	copy(&ve[0], &ve[5], out);
	cout<<endl;*/

	vector<double>ve;
	int temp = 0;
	
	cout<<"请输入你要插入的值："<<endl;
	while(cin>>temp && temp != -1)
		ve.push_back(temp);

	sort(ve.begin(), ve.end());
	ostream_iterator<double, char>out(cout, " ");
	copy(ve.begin(), ve.end(), out);

	int size = ve.size();
	valarray<double>va(size);
	for (int i = 0; i < size; i++)
		va[i] = ve[i];
	cout<<endl;

	valarray<double>va2(size);
	va2 = sqrt(va);
	copy(&va2[0], &va2[size], out);

	cout<<endl;
	valarray<double>va3(size);
	va3 = va2 + 2.01 + va;
    copy(&va3[0], &va3[size], out);

	return 0;
}