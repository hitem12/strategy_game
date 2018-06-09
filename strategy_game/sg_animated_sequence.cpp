#include "sg_animated_sequence.h"



void sg_animated_sequence::add_frame(sf::Texture * texture)
{
	T_seq.push_back(texture);
}

void sg_animated_sequence::set_sequence(vector<sf::Texture*> vec_tex)
{
	T_seq = vec_tex;
}

sg_animated_sequence::sg_animated_sequence(string a_name)
	: name(a_name), current_frame{ 0 }
{
	sf::Texture * texture;
	for (int i = 0; i < 31; i++)
	{
		texture = new sf::Texture;
		string i_s = to_string(i);
		texture->loadFromFile("graphics\\sprites\\cannon\\" + string(4 - i_s.size(), '0') + i_s + ".png");
		
		T_seq.push_back(texture);
		texture = nullptr;
	
	}
}

sf::Texture * sg_animated_sequence::get_current_texture()
{
	if (!T_seq.empty())
	{
		if (current_frame == T_seq.size())
			current_frame = 0;
		return T_seq[current_frame++];
		//current_frame++;

		
	}
	else
		return nullptr;
}


sg_animated_sequence::~sg_animated_sequence()
{
	for (auto x : T_seq)
		delete x;
	
}
