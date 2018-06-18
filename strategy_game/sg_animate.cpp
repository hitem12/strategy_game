#include "sg_animate.h"



sg_animate::sg_animate(sf::Sprite * spr) 
	: current_animation{ 0 }, frame_time { sf::seconds(0.01) }, is_Paused{true}, old_vec {sf::Vector2f(0,0)}
{
	
	sg_animation_builder cannon{"cannon"};
	animations = cannon.get_seq();
	sprite = spr;
	sprite->setTexture(*animations[current_animation]->get_current_texture(), false);
}


sg_animate::~sg_animate()
{
}

void sg_animate::operator()(sf::Time lap_time, sf::Vector2f vec_mv)
{


	
	if (!is_Paused) //If it's not be paused
	{
		
		time += lap_time;	
		if (time > frame_time)		// and time is grater then animation time
		{	//TODO optimalization and make more elastic swiching animation
			
			if (!!vec_mv && old_vec != vec_mv)
			{
				float a = sqrtf(pow(vec_mv.x, 2) + pow(vec_mv.y, 2));
				vec_mv.x /= a;
				vec_mv.y /= a;
				//cout << setw(10) << vec_mv << "            \r";
				
				if (old_vec != vec_mv)
				{
					if (is_left)
					{
						sprite->move(sf::Vector2f(-60, 0));
						is_left = false;
					}
					sprite->setScale(1.0f,1.0f);
					if (vec_mv.y >= 0.75)
						Swich_Animation("move_S");
					else if (vec_mv.y <= -0.75)
						Swich_Animation("move_N");
					else
					{
						if (vec_mv.y >= 0.25)
							Swich_Animation("move_SE");
						else if (vec_mv.y < -0.25)
							Swich_Animation("move_NE");
						else
							Swich_Animation("move_E");
						if (vec_mv.x < 0)
						{
							
							sprite->setScale(-1.0f, 1.0f);
							sprite->move(sf::Vector2f(60, 0));
							is_left = true;
						}
						old_vec = vec_mv;
					}
				}

				next_sprite();
				//cout << sprite->getTexture()->getSize() << endl;
				time = sf::Time::Zero;
			}

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

void sg_animate::Swich_Animation(string anim_name)
{
	int i{0};
	for (auto a : animations)
	{	
		if (a->getName() == anim_name)
		{
			current_animation = i;
			break;
		}
		i++;
		
	}
}
