#pragma once
#include "Enemy.h"
#include <iostream>
using namespace std;


class Role
{
private:
	int x;
	int y;

public:
	Role(int a, int b);

	void Get(Enemy&);

	~Role(void);
};
