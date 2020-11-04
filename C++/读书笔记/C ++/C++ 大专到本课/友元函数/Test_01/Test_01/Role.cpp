#include "Role.h"

int Role::t = 100;

Role::Role(int a, int b):x(a),y(b){}

void Getxy(Role r)
{
	cout<< r.x <<endl;
	cout<< r.y <<endl;
}



Role::~Role(){}