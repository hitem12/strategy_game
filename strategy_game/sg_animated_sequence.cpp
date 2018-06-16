#include "sg_animated_sequence.h"



void sg_animated_sequence::add_frame(sf::Texture * texture)
{
	T_seq_v.push_back(texture);
}

void sg_animated_sequence::add_frame(string pic_dir)
{
	sf::Texture * texture = new sf::Texture;
	texture->loadFromFile(pic_dir);
	T_seq_v.push_back(texture);
	texture = nullptr;
}

void sg_animated_sequence::set_sequence(vector<sf::Texture*> vec_tex)
{
	T_seq_v = vec_tex;
}

sg_animated_sequence::sg_animated_sequence(string a_name)
	: name(a_name), current_frame{ 0 }
{
	//sf::Texture * texture;
	//for (int i = 0; i < 31; i++)
	//{
	//	texture = new sf::Texture;
	//	string i_s = to_string(i);
	//	string dir{ "graphics/sprites/cannon/" + string(4 - i_s.size(), '0') + i_s + ".png" };
	//	texture->loadFromFile(dir);
	//	//texture->loadFromFile("graphics\\sprites\\cannon\\" + string(4 - i_s.size(), '0') + i_s + ".png");
	//	
	//	T_seq_v.push_back(texture);
	//	texture = nullptr;
	//	
	//}
}

sf::Texture * sg_animated_sequence::get_current_texture()
{
	if (!T_seq_v.empty())
	{
		if (current_frame == T_seq_v.size())
			current_frame = 0;
		return T_seq_v[current_frame++];
		//current_frame++;

		
	}
	else
		return nullptr;
}


sg_animated_sequence::~sg_animated_sequence()
{
	for (auto x : T_seq_v)
		delete x;
	
}
