#pragma once

#include <SFML/Graphics.hpp>

class Animation 
{
public:
	//constructor
	Animation();
	//function
	void Animate(sf::Sprite* sprite, sf::Vector2u imageCount, float switchTime);
	void Update(int row, float deltaTime);

	sf::IntRect uvRect;
private:
	//valuable
	float totalTime;
	float switchTime;
	
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	
};

