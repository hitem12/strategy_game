#pragma once
#include <vector>
#include "global_function.h"
#include "sg_animated_sequence.h"
#include "sg_animation_builder.h"
#include <iostream>
#include "sg_animation_builder.h"
#include <iomanip>



using namespace std;
class sg_animate
{	
	bool is_left{ 0 };
	sf::Vector2f old_vec;
	sf::Time time;
	sf::Sprite * sprite;
	bool is_Paused;
	sf::Time frame_time;
	unsigned int current_animation;
	vector<sg_animated_sequence*> animations;	
	
	void next_sprite() {
		sprite->setTexture(*animations[current_animation]->get_current_texture(), true);
	}
public:
	
	void add_animation(); 
	sg_animate(sf::Sprite*);
	~sg_animate();
	void operator()(sf::Time, sf::Vector2f vec_mv = sf::Vector2f(0,0));
	void Start();
	void Stop();
	void Pause();
	void Swich_Animation();
	void Swich_Animation(string anim_name);

	void set_sequence(vector<sf::Texture*> vec_tex);
	void add_frame(sf::Texture * texture);

};

