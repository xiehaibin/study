#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

class Hun
{
public :
	int how;
	Hun(int a) : how(a) {}
};

void ShowReview(const Hun hu);
bool operator<(const Hun & p1, const Hun & p2);

int main(void)
{
	Hun hun[6] = {Hun(-1), Hun(7), Hun(4), Hun(10), Hun(6), Hun(8)};

	vector<Hun>vu(hun, hun+6);
	typedef vector<Hun>::iterator iterator;

    //for_each(vu.begin()+1, vu.end(), ShowReview);
	//cout<<endl<<endl;

	sort(vu.begin(), vu.end());
	for_each(vu.begin()+1, vu.end(), ShowReview);


	int t = 0;
	iterator first = vu.begin();

Start:
    cout<<"请输入要打出去的牌：";
	cin>>t;

	first = vu.begin();
	for(first; first != vu.end(); first++)
	{
		if ( first->how == t)
		{
			vu.erase(first);
			first = vu.begin();
		}
	}
	for_each(vu.begin()+1, vu.end(), ShowReview);
	if (vu.size() > 1)
		goto Start;

	return 0;
}

void ShowReview(const Hun hu)
{
	cout<<"how: "<< hu.how <<endl;
}

bool operator<(const Hun & p1, const Hun & p2)
{
	if (p1.how < p2.how)
		return true;
	else if (p1.how == p2.how)
		return true;
	else
		return false;
}