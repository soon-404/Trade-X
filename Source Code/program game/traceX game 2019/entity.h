#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <vector>
#include <concurrent_vector.h>
#include <DirectXPackedVector.h>
#include <iostream>
#include <stdio.h>
#include <random>
#include <deque>
#include <list>
#include <functional>
#include <time.h>
#include <fstream>


class entity
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
};
