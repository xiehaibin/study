#pragma once

class Enemy
{
private:
	int x;
	int y;

public:
	friend class Role;
	Enemy(int a, int b);
	~Enemy(void);
};
