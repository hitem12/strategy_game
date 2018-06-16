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

	//sg_unit cannon(400,300);
	sg_cannon cannon(400,300);
	sf::Clock clock;
	sf::Clock clock2;
	int frames{ 0 };
//	CreateDirectory(TEXT("tujestem"), NULL);
	sf::Vector2i ala;
	//char NPath[MAX_PATH];
	//GetCurrentDirectoryA(MAX_PATH, NPath);
	//cout << NPath << endl;


	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
			{
				//cout << "x = " <<  sf::Mouse::getPosition(window).x << " y = " << sf::Mouse::getPosition(window).y << "       \r";

				cannon.set_destination(sf::Mouse::getPosition(window));
			}
		}
		cannon.actions(clock.getElapsedTime());
	//	cannon.actions(clock.getElapsedTime());
		//ala = sf::Mouse::getPosition(window);

		//	cout << "x = " << ala.x << " y = " << ala.y <<" " << clock.getElapsedTime().asMicroseconds() <<"                     \r";

		window.clear(sf::Color(0, 250, 0));


		window.draw(cannon.getSprite());
		window.display();
		//cout << clock.getElapsedTime().asMicroseconds() << "        \r";
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