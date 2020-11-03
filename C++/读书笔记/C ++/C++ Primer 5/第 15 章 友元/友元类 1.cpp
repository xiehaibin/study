#include <iostream>
using namespace std;

class Role
{
private :
	friend class Key; // 让整个Key类成为友元 并不需要前向声明，因为友元本身已经指出了Key是一个类
	int hp;

public :
	Role(int hemo)
	{
		hp = hemo;
	}
    
protected :
	void Show(void) const
	{
		cout<<"hp: "<< hp <<endl;
	}

	void SetHp(void) 
	{
	   if ( 95 > hp)
		   hp += 5;
	   else
		   cout<<" 血量以满 "<<endl;
	}
};

class Key
{
public :
	void Show(Role & role)
	{
		role.Show();
	}

	void SetHp(Role & role) 
	{
		role.SetHp();
	}
};

int main(void)
{
	Role role(35);
	Key key;

	key.Show(role);
	key.SetHp(role);
	return 0;
}