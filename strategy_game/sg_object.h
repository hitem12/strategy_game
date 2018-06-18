#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "global_function.h"
using namespace std;
class sg_object
{
protected:

	sf::Sprite sprite;
	sf::Texture texture;
	sg_object(float x = 0, float y = 0);
	sg_object(sf::Vector2f);
public:
	
	sf::Sprite getSprite();
	
	virtual void actions(sf::Time frame_t) {};
	sg_object(float x, float y, sf::Texture tex) : sg_object(sf::Vector2f(x, y), tex) {};
	sg_object(sf::Vector2f, sf::Texture);


	virtual ~sg_object();
};

