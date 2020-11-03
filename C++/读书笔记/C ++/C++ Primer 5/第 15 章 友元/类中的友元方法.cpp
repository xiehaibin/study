#include <iostream>
using namespace std;

class Role; // 检查原型时，所有的编绎器都要知道 Role 是一个类 而此处前向声明提供了这样的信息
            // 当编绎器到在 真正的方法定义时， 它已经读取了Role 类的声明

class Key
{
public :
	void Show(Role & role);  // 这里将调用Role的一个方法  所以编绎器必须看到Role的类声明 这样
	                         // 才知道Role有哪些方法， 但下如看到的哪样 Role声明位于Key声明之
	                         // 后， 解决的方法是 使KEY类声明中只包含方法声明，并将实际的方法
	                         // 定义放在 Role后，
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
		   cout<<" 血量以满 "<<endl;
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