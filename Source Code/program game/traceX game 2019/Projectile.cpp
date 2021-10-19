#include "Projectile.h"

Projectile::Projectile()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setFillColor(sf::Color::Green);

}

void Projectile::update()
{
	if (direction == 1) // Up
	{
		sprite.move(0, -movementSpeed);
	}
	if (direction == 2) // Down
	{
		sprite.move(0, movementSpeed);	
	}
	if (direction == 3) // Left
	{
		sprite.move(-movementSpeed, 0);
	}
	if (direction == 4) // Right
	{
		sprite.move(movementSpeed, 0);
	}
}
