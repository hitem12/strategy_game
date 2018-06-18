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

}

sg_cannon::sg_cannon(sf::Vector2f xy) 
		: sg_object(xy), move(&sprite), anime(&sprite)
{
	anime.Start();
	
}

sg_cannon::sg_cannon(float x, float y) : sg_cannon(sf::Vector2f(x,y))
{
}


sg_cannon::~sg_cannon()
{
}
