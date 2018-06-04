#pragma once
#include "sg_object.h"
#include <math.h>
#include <iomanip> 
class sg_unit :
	public sg_object
{
	
	sf::Vector2f  destination;
	float speed{ 1.0f };
protected:
	sf::Time l_time;
public:

	sg_unit(float x = 0, float y = 0);
	sg_unit(sf::Vector2f);
	~sg_unit();
	void move(sf::Vector2f);
	void move(sf::Vector2i);
	void actions();
	void actions(sf::Time n_time);
};

