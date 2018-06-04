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
	sf::Clock clock;
public:
	
	sf::Sprite getSprite();
	
	sg_object(float x = 0, float y = 0);
	sg_object(sf::Vector2f);
	~sg_object();
};

