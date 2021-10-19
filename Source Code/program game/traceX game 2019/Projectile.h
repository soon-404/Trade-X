#pragma once

#include "entity.h"

class Projectile : public entity
{
public:
	int movementSpeed = 10;
	int attackDamage = 5;
	int direction = 1;
	bool destroy = false;
	bool shooterPlasma = false;
	
	Projectile();
	void update();
};

