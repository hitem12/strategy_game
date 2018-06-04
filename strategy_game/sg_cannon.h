#pragma once
#include "sg_unit.h"

class sg_cannon :
	public sg_unit
{
	int count{ 0 };
protected:
	sf::Texture* texture;
	//vector<sf::Texture> texture;
public:
	
	void actions();
	sg_cannon(sf::Vector2f xy);
	sg_cannon(float x, float y);
	~sg_cannon();
};

