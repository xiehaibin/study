#include "Role.h"
#include "Enemy.h"

int main(void)
{
	Role role(10,20);
	Getxy(role);

	Enemy enemy(100, 200);

	role.GetEnemy(enemy);
	return 0;
}