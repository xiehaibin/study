#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[3] = {2,3,1};

int main(void)
{
	//string let;
     vector<int>va(a, a+3);
     
	 sort(va.begin(), va.end());
	 ostream_iterator<int, char>out_iter(cout, " ");
	while(next_permutation(va.begin(), va.end()))
	      copy(va.begin(), va.end(), out_iter);

	//sostream_iterator<int>(cout, " ");
			//cout<<  <<endl;


	/*while(cin>>let && let != "no")
	{
		sort(let.begin(), let.end());

		while(next_permutation(let.begin(), let.end()))
			cout<< let <<endl;
	}*/
	return 0;
}