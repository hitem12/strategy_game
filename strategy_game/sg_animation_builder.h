#pragma once
#include "sg_animated_sequence.h"
#include <string>
#include <vector>
#include "pugixml\pugixml.hpp"

using namespace std;


class sg_animation_builder
{

	string object_name;
	vector<sg_animated_sequence*> seq;
public:
//	sg_animated_sequence finish_seq();
	vector<sg_animated_sequence*> get_seq();
	sg_animation_builder(string obj_name);
	~sg_animation_builder();
};

