#pragma once
#include "Role.h"

class Enemy
{
private :
	int x;
	int y;

public:
	Enemy(int a, int b);
	~Enemy();
	friend void Role::GetEnemy(Enemy&);
};