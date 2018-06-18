#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
class sg_animation_builder;

class sg_animated_sequence
{
	friend sg_animation_builder;
	
	
	unsigned int current_frame;
	string name;
	void add_frame(sf::Texture *);
	void add_frame(string pic_dir);
	void set_sequence(vector<sf::Texture*>);
	vector<sf::Texture*> T_seq_v;
	sf::Texture* T_seq;
	sg_animated_sequence(string a_name);
public:
	
	string getName() { return name; };
	sf::Texture * get_current_texture();
	~sg_animated_sequence();
};

