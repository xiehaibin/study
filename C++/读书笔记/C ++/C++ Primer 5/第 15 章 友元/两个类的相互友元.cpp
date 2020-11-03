#include <iostream>
using namespace std; 

class Role
{
private :
	int hp;

	friend class Key;

public :
	Role(int hemo)
	{
		hp = hemo;
	}

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

	void SetKey(Key & key);   // 必须声明不能定义
};

class Key
{
private :
	bool b;

	friend class Role;

public :
	Key(bool n) : b(n) {}

	void Show(Role & role)
	{
		role.Show();
	}
	void SetHp(Role & role) 
	{
		role.SetHp();
	}

	void Show(void) 
	{
		cout.setf(ios::boolalpha);
		cout<<"key : "<<b <<endl;
		b = false;
	}
};

inline void Role::SetKey(Key & key)  // 也必须在Key 之后定义
{
	key.b = true;
} 
// 如果不希望 SetKey 是内联的， 则应在一个单独的方法定义文件中定义它

int main(void)
{
	Role role(35);
	Key key(false);

	key.Show(role);
	key.SetHp(role);
	role.SetKey(key);
	key.Show();
	return 0;
}