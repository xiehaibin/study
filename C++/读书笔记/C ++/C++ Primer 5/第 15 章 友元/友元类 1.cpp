#include <iostream>
using namespace std;

class Role
{
private :
	friend class Key; // ������Key���Ϊ��Ԫ ������Ҫǰ����������Ϊ��Ԫ�����Ѿ�ָ����Key��һ����
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
		   cout<<" Ѫ������ "<<endl;
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