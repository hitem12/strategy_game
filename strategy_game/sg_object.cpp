
#include "sg_object.h"

//TODO to sie nie powinno zawsze wykonywac

sg_object::sg_object(float x, float y )
{
	//if (texture.loadFromFile("graphics\\sprites\\cannon\\0000.png") == false) cout << "dont recognize texture\n";
	//sprite.setTexture(texture);
	sprite.setPosition(x, y);
	
}

sg_object::sg_object(sf::Vector2f xy)
{
	//if (texture.loadFromFile("graphics\\sprites\\cannon\\0001.png") == false) cout << "dont recognize texture\n";
	//sprite.setTexture(texture);
	sprite.setPosition(xy);
}


sg_object::~sg_object()
{
}
sf::Sprite sg_object::getSprite()
{
	return sprite;
}