#pragma once
#include <SFML\Graphics.hpp>
#include "sg_object.h"
class move
{
	sg_object * object;
	sf::Clock clock;
public:
	move();
	~move();
};

