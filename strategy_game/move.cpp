#include "move.h"



move::move()
{
}

void actions(sf::Time n_time)
{
	//static sf::Time l_time;
	//	sf::Time n_time = clock.getElapsedTime();
	sf::Vector2f vec = (destination - sprite.getPosition());

	if (vec != sf::Vector2f(0, 0))
	{
		if (abs(vec.x) > speed || abs(vec.y) > speed)
		{
			float a = sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
			vec.x /= a;
			vec.y /= a;

			a = (n_time.asMicroseconds() - l_time.asMicroseconds()) * 0.0001;
			vec.x *= speed * a;
			vec.y *= speed * a;
			sprite.move(vec);

		}

		else
		{
			sprite.setPosition(destination);
		}
	}


}

move::~move()
{
}
