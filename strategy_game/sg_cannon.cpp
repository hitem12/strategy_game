#include "sg_cannon.h"



void sg_cannon::set_destination(sf::Vector2f destination)
{
	move.destination = destination;
}

void sg_cannon::set_destination(sf::Vector2i xy) 
{
	sf::Vector2f xyf;
	xyf.x = xy.x;
	xyf.y = xy.y;
	set_destination(xyf);
	
}

void sg_cannon::set_destination(float x, float y) 
{
	set_destination(sf::Vector2f(x, y));
}

void sg_cannon::actions(sf::Time frame_t)
{
	auto vec = move(frame_t);
	anime(frame_t, vec);
	//cout << sprite.getTexture() << "                  \r";
	//sf::Time n_time = clock.getElapsedTime();
	//sg_unit::actions(n_time);
	//static int i;
	////static sf::Time l_time;
	//
	//
	//if (n_time.asMicroseconds() - l_time.asMicroseconds() > 1000)
	//{
	//	sprite.setTexture(texture[i%3]);
	//	i++;
	//	clock.restart();
	//	l_time.Zero;
	//}
	//l_time = n_time;
}

sg_cannon::sg_cannon(sf::Vector2f xy) 
		: sg_object(xy), move(&sprite), anime(&sprite)
{
	
	//texture = new sf::Texture[31];
	//for (int i = 0; i < 31; i++)
	//{
	//	string i_s = to_string(i);

	//	texture[i].loadFromFile("graphics\\sprites\\cannon\\" + string(4 - i_s.size(), '0') + i_s + ".png");
	//}
	//sprite.setTexture(texture[0]);
	//sprite.setTexture( *anime.animations[0]->T_seq[7]);
	anime.Start();
	
}

sg_cannon::sg_cannon(float x, float y) : sg_cannon(sf::Vector2f(x,y))
{
}


sg_cannon::~sg_cannon()
{
}
