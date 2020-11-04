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
			cout<<" Ѫ������ "<<endl;
	}

	void SetKey(Key & key);   // �����������ܶ���
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

inline void Role::SetKey(Key & key)  // Ҳ������Key ֮����
{
	key.b = true;
} 
// �����ϣ�� SetKey �������ģ� ��Ӧ��һ�������ķ��������ļ��ж�����

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