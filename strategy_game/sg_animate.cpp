#include "sg_animate.h"



sg_animate::sg_animate(sf::Sprite * spr)
{
	is_Paused = true;
	frame_time = sf::seconds(0.01);
	current_animation = 0;
	sg_animated_sequence * anime;
	anime = new sg_animated_sequence { "cannon" };
	animations.push_back(anime);
	sprite = spr;
}


sg_animate::~sg_animate()
{
}

void sg_animate::operator()(sf::Time lap_time)
{
	
	if (!is_Paused) //If it's not be paused
	{
		time += lap_time;	
		if (time > frame_time)		// and time is grater then animation time
		{	
			cout << "jestem"<< endl;
			sprite->setTexture(*animations[current_animation]->get_current_texture());
			time = sf::Time::Zero;
			
		}
	}
}

void sg_animate::Start()
{
	is_Paused = false;
}

void sg_animate::Pause()
{
	is_Paused = true;
}
