#include "enemy.h"

enemy::enemy()
{
	rect.setSize(sf::Vector2f(96, 96));
	rect.setPosition(400, 100);
	rect.setFillColor(sf::Color::Blue);
	rect.setOrigin(48, 48);
	sprite.setOrigin(48, 48);
	sprite.setTextureRect(sf::IntRect(0, 0, 96, 96));
}

void enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

