#include "sg_move.h"


sg_move::sg_move(sf::Sprite * sprite_to_move, float unit_speed)
	: sprite(sprite_to_move), speed(unit_speed), destination(sprite_to_move->getPosition())
{
}



void sg_move::operator()(sf::Time frame_t)
{	
	//static sf::Time l_time;
	//	sf::Time n_time = clock.getElapsedTime();
	sf::Vector2f vec = (destination - sprite->getPosition());

	if (vec != sf::Vector2f(0, 0))
	{
		if (abs(vec.x) > speed || abs(vec.y) > speed)
		{
			float a = sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
			vec.x /= a;
			vec.y /= a;

			a = frame_t.asMicroseconds() * 0.0001;
			vec.x *= speed * a;
			vec.y *= speed * a;
			sprite->move(vec);

		}

		else
		{
			sprite->setPosition(destination);
		}
	}

}









sg_move::~sg_move()
{
}
