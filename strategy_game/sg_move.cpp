#include "sg_move.h"


sg_move::sg_move(sf::Sprite * sprite_to_move, float unit_speed)
	: sprite(sprite_to_move), speed(unit_speed), destination(sprite_to_move->getPosition())
{
}



sf::Vector2f sg_move::operator()(sf::Time frame_t)
{	
	constexpr int tr{8}; // range of unit teleportation (part of speed)

	sf::Vector2f vec = (destination - sprite->getPosition());
	

	if (!!vec)
	{
		if (abs(vec.x) > speed/tr || abs(vec.y) > speed/tr)
		{
			float a = sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
			vec.x /= a;
			vec.y /= a;
			
			a = frame_t.asMicroseconds() * 0.0001;
			vec.x *= speed * a;
			vec.y *= speed * a;
			sprite->move(vec);
			return vec;

		}

		else
		{
			sprite->setPosition(destination);
			return sf::Vector2f(0,0);
		}
	}
	else 
	{
		return vec;
	}
	
}




sg_move::~sg_move()
{
}
