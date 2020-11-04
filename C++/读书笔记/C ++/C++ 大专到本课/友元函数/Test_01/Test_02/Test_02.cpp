#include "Role.h"
#include "Enemy.h"

int main(void)
{
	Role role(10,20);
	Enemy enemy(100,200);

	role.Get(enemy);
	return 0;
}