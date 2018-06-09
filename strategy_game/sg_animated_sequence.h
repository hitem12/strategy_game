#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "sg_animation_builder.h"
#include <iostream>
using namespace std;
class sg_animated_sequence
{
//	friend sg_animation_builder;
	
	string name;
	unsigned int current_frame;

	void add_frame(sf::Texture *);
	void set_sequence(vector<sf::Texture*>);
	
public:
	vector<sf::Texture*> T_seq;
	sg_animated_sequence(string a_name);
	string getName() { return name; };
	sf::Texture * get_current_texture();
	~sg_animated_sequence();
};

