#pragma once
#include <SFML\Graphics.hpp>
#include "sg_object.h"

class sg_move
{
	sf::Sprite * sprite;
public:
	void operator()(sf::Time frame_t);
	sf::Vector2f destination;
	float speed;
	sg_move(sf::Sprite *, float unit_speed = 10);
	~sg_move();
};

