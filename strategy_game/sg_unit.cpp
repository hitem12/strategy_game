#include "sg_unit.h"



sg_unit::sg_unit(float x, float y) : sg_object(x,y), destination(sf::Vector2f(x,y))
{
}

sg_unit::sg_unit(sf::Vector2f xy) : sg_object(xy), destination(xy)
{
}


sg_unit::~sg_unit()
{
}

void sg_unit::move(sf::Vector2f xy)
{
	destination = xy;
	//sprite.setPosition(xy);
}

void sg_unit::move(sf::Vector2i xy)
{
	sf::Vector2f xyf;
	xyf.x = xy.x;
	xyf.y = xy.y;
	destination = xyf;
}

void sg_unit::actions(sf::Time n_time)
{
	//static sf::Time l_time;
//	sf::Time n_time = clock.getElapsedTime();
	sf::Vector2f vec = ( destination-sprite.getPosition() );

	if(vec != sf::Vector2f(0,0))
	{
		if (abs(vec.x) > speed || abs(vec.y) > speed)
		{
			float a = sqrtf(pow(vec.x, 2) + pow(vec.y, 2));
			vec.x /= a;
			vec.y /= a;

			a = (n_time.asMicroseconds() - l_time.asMicroseconds() ) * 0.0001;
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

void sg_unit::actions()
{
	sf::Time n_time = clock.getElapsedTime();
	actions(n_time);
	l_time = n_time;
}

