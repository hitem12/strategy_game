#include "sg_cannon.h"



void sg_cannon::actions()
{
	sf::Time n_time = clock.getElapsedTime();
	sg_unit::actions(n_time);
	static int i;
	//static sf::Time l_time;
	
	
	if (n_time.asMicroseconds() - l_time.asMicroseconds() > 1000)
	{
		sprite.setTexture(texture[i%3]);
		i++;
		clock.restart();
		l_time.Zero;
	}
	l_time = n_time;
}

sg_cannon::sg_cannon(sf::Vector2f xy) : sg_unit(xy)
{
	
	texture = new sf::Texture[31];
	for (int i = 0; i < 31; i++)
	{
		string i_s = to_string(i);

		texture[i].loadFromFile("graphics\\sprites\\cannon\\" + string(4 - i_s.size(), '0') + i_s + ".png");
	}
	sprite.setTexture(texture[0]);
	
}

sg_cannon::sg_cannon(float x, float y) : sg_cannon(sf::Vector2f(x,y))
{
}


sg_cannon::~sg_cannon()
{
}
