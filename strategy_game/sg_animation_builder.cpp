#include "sg_animation_builder.h"






vector<sg_animated_sequence*> sg_animation_builder::get_seq()
{
	return seq;
}

sg_animation_builder::sg_animation_builder(string obj_name)
{
	object_name = obj_name;

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("animate.xml");
	//cout << result.description() << endl;
	pugi::xml_node obj = doc.child("Animations").child(obj_name.c_str());
	
	

	for (pugi::xml_node anime : obj)
	{
		
		for (pugi::xml_node type : anime)
		{
			seq.push_back(new sg_animated_sequence (string(anime.name()) + '_' + string(type.name())));
			
			for (pugi::xml_node frame : type)
			{
				string dir = obj.attribute("dir").as_string() + string(frame.child_value());
				//cout << dir << endl;
				seq.back()->add_frame(dir);

			}
			
		}
	}
}

sg_animation_builder::~sg_animation_builder()
{
}
