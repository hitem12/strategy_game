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
				seq.back()->add_frame(obj.attribute("dir").as_string() + string(frame.child_value()));
				//cout << string(anime.name()) + '_' + string(type.name()) << endl;
				//cout << " dir = " << obj.attribute("dir").as_string() <<  string(frame.child_value()) << endl;
				//cout << "@" <<string(frame.child_value());
					
				//cout << anime.name() << "_" << type.name() << " dir  = " << obj.attribute("dir").as_string() << frame.child_value() << endl;
			}
			
		}
	}
}

sg_animation_builder::~sg_animation_builder()
{
}
