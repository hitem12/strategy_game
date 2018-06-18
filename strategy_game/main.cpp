#include <SFML/Graphics.hpp>
#include <cmath>
#include "sg_cannon.h"
#include "global_function.h"
#include <windows.h>

constexpr int hight = 800;
constexpr int lengh = 600;



int main()
{
	sf::RenderWindow window(sf::VideoMode(hight, lengh), "Super game");

	sg_cannon cannon(400,300);
	//sg_cannon cannon2(300,500);
	sf::Clock clock;
	sf::Clock clock2;

	int frames{ 0 };

	sf::Vector2i ala;

	//Show current dir
	//char NPath[MAX_PATH];
	//GetCurrentDirectoryA(MAX_PATH, NPath);
	//cout << NPath << endl;

	sf::Texture tree_t;
	tree_t.loadFromFile("graphics/terrain/Tree-sprites-standard-terrain.png", sf::IntRect(sf::Vector2i(132, 0), sf::Vector2i(66, 78)));
	sg_object tree(sf::Vector2f(10.0f, 20.0f), tree_t);
	sf::Vector2i mause_pos;
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				//mause_pos = sf::Mouse::getPosition(window);
				
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				//cout << "x = " <<  sf::Mouse::getPosition(window).x << " y = " << sf::Mouse::getPosition(window).y << "       \r"; //show mause position
				cannon.set_destination(sf::Mouse::getPosition(window));
			}
		}
		cannon.actions(clock.getElapsedTime());


		window.clear(sf::Color(0, 250, 0));

		window.draw(tree.getSprite());
		window.draw(cannon.getSprite());
	//	window.draw(cannon2.getSprite());
		

		window.display();
		//cout << clock.getElapsedTime().asMicroseconds() << "        \r"; //show single frame time
		
		//show frame per sec
		frames++;
		if (clock2.getElapsedTime().asMicroseconds() >= 1000000)
		{
			cout << "frames per sec = " << frames << "             \r";
			frames = 0;
			clock2.restart();
		}
		
		clock.restart();
	} 
	return 0;
}