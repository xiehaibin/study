#pragma once
#include <iostream>
using namespace std;

class Enemy;

class Role
{
public:
	static int t;

private :
	int x;
	int y;

public:
	Role(int a, int b);
	~Role();
	friend void Getxy(Role); 
	void GetEnemy(Enemy& e);
};