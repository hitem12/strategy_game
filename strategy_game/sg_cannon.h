#pragma once
#include "sg_object.h"
#include "sg_move.h"
#include "sg_animate.h"




class sg_cannon :
	public sg_object
{
	int count{ 0 };
protected:
	sg_move move;
	sg_animate anime;
public:
	
	void set_destination(sf::Vector2f);
	void set_destination(sf::Vector2i);
	void set_destination(float x, float y);

	void actions(sf::Time frame_t);
	sg_cannon(sf::Vector2f xy);
	sg_cannon(float x, float y);
	~sg_cannon();
};

