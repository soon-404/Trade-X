#pragma once
#include "entity.h"
#include "Animation.h"
class player : public entity, public Animation
{
public:
	//valuable
	int movementSpeed = 5;
	int attackDamage = 5;
	int counterWalking = 0;
	int checkDirection = 0;
	int blood = 100;
	int timerobot;
	int timerobotmove;
	bool canMoveUp = false;
	bool canMoveDown = false;
	bool canMoveLeft = false;
	bool canMoveRight = false;
	//constructor
	player();

	//function
	void update();
	void updateMovement();
	sf::Clock clock;
};