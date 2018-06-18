
#include "sg_object.h"



sg_object::sg_object(float x, float y ) : sg_object(sf::Vector2f(x,y))
{	
}

sg_object::sg_object(sf::Vector2f xy)
{
	sprite.setPosition(xy);
}


sg_object::sg_object(sf::Vector2f xy, sf::Texture tex) : sg_object(xy)
{	
	texture = tex;
	sprite.setTexture(texture);
}

sg_object::~sg_object()
{
}
sf::Sprite sg_object::getSprite()
{
	
	return sprite;
}