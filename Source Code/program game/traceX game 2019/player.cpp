#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(128, 128));
	rect.setPosition(500, 500);
	rect.setFillColor(sf::Color::Blue);
	rect.setOrigin(64, 64);
	sprite.setPosition(960, 540);
	sprite.setOrigin(64, 64);
	sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
	
}

void player::update()
{
	
}

void player::updateMovement()
{
	timerobot = clock.getElapsedTime().asMilliseconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > 40)
	{
		checkDirection = 1;
		canMoveUp = true;
		if (canMoveUp == true && canMoveDown == false && canMoveLeft == false && canMoveRight == false)
		{
			sprite.move(0, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * 128, 128, 128, 128));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y < 1030)
	{
		checkDirection = 2;
		canMoveDown = true;
		if (canMoveUp == false && canMoveDown == true && canMoveLeft == false && canMoveRight == false)
		{
			sprite.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * 128, 0, 128, 128));//ยาว กว้าง
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > 40)
	{
		checkDirection = 3;
		canMoveLeft = true;
		if (canMoveUp == false && canMoveDown == false && canMoveLeft == true && canMoveRight == false)
		{
			sprite.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * 128, 256, 128, 128));//ยาว กว้าง
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x < 1870)
	{
		checkDirection = 4;
		canMoveRight = true;
		if (canMoveUp == false && canMoveDown == false && canMoveLeft == false && canMoveRight == true)
		{
			sprite.move(movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * 128, 384, 128, 128));//ยาว กว้าง
		}
	}
	
	if (timerobot % 5== 0)
	{
		counterWalking++;
	}
	if (counterWalking == 3)
	{
		counterWalking = 0;
	}
}
