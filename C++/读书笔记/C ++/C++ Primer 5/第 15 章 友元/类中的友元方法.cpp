#include <iostream>
using namespace std;

class Role; // ���ԭ��ʱ�����еı�������Ҫ֪�� Role ��һ���� ���˴�ǰ�������ṩ����������Ϣ
            // ������������ �����ķ�������ʱ�� ���Ѿ���ȡ��Role �������

class Key
{
public :
	void Show(Role & role);  // ���ｫ����Role��һ������  ���Ա��������뿴��Role�������� ����
	                         // ��֪��Role����Щ������ �����翴�������� Role����λ��Key����֮
	                         // �� ����ķ����� ʹKEY��������ֻ������������������ʵ�ʵķ���
	                         // ������� Role��
	void SetHp(Role & role);
	void GetHemo(Role & role);
};

class Role
{
private :
	int hp;

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

	friend void Key::GetHemo(Role & role);
};

void Key::Show(Role & role)
{
	role.Show();
}
void Key::SetHp(Role & role) 
{
	role.SetHp();
}
void Key::GetHemo(Role & role)
{
	cout<<"hp: "<< role.hp <<endl;
}


int main(void)
{
	Role role(35);
	Key key;

	key.Show(role);
	key.SetHp(role);
	key.GetHemo(role);
	return 0;
}