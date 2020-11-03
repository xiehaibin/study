#include "Enemy.h"

Enemy::Enemy(int a, int b):x(a),y(b){}

void Role::GetEnemy(Enemy &e)
{
	cout<<"x: "<<e.x<<endl;
	cout<<"y: "<<e.y<<endl;
}

Enemy::~Enemy(){}