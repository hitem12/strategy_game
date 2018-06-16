#pragma once
#include <vector>
#include "sg_animated_sequence.h"
#include "sg_animation_builder.h"
#include <iostream>

using namespace std;
class sg_animate
{
	sf::Time time;
	
	sf::Sprite * sprite;
	bool is_Paused;
	sf::Time frame_time;
	unsigned int current_animation;
public:
	vector<sg_animated_sequence*> animations;
	void add_animation(); 
	sg_animate(sf::Sprite*);
	~sg_animate();
	void operator()(sf::Time, sf::Vector2f vec_mv = sf::Vector2f(0,0));
	void Start();
	void Stop();
	void Pause();
	void Swich_Animation();

	void set_sequence(vector<sf::Texture*> vec_tex);
	void add_frame(sf::Texture * texture);

};

