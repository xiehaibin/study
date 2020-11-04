#include "Role.h"

Role::Role(int a, int b):x(a),y(b){}

void Role::Get(Enemy& e)
{
	cout<<"X: "<<e.x<<endl;
	cout<<"Y: "<<e.y<<endl;
}

Role::~Role(void){}
