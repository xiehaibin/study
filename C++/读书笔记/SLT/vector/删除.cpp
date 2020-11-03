#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define SIZE 6

class Enemy
{
public :
	int hp;
	Enemy(int hemo) : hp(hemo) {}
	void Show(void) const
	{
		cout<<"HP: "<< hp <<endl;
	}
};

int main(void)
{
	Enemy* pe[SIZE] = {new Enemy(-1), new Enemy(23), new Enemy(40), new Enemy(100), new Enemy(87), new Enemy(90)};

	vector<Enemy*>vc(pe, pe+SIZE);
	typedef vector<Enemy*>::iterator iterator;
	iterator first = vc.begin();

	for(first; first != vc.end(); first++)
		(*first)->Show();
	cout<<endl;


	int t;

Start:
	cout<<"请输入要删除的对象：";
	cin>>t;

	first = vc.begin();
	for (first; first != vc.end(); first++)
	{
		if ((**first).hp == t) 
		{
			vc.erase(first);
			first = vc.begin();
		}
	}
    
	first = vc.begin()+1;
	for (first; first != vc.end(); first++)
	{
		(*first)->Show();
	}

	cout<< vc.size() <<endl;

	if (vc.size() != 1)
	    goto Start;

	return 0;
}