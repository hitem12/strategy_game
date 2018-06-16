#pragma once
#include <iostream>
#include <string>
#include<SFML\Graphics.hpp>

using namespace std;

ostream & operator<<(ostream & screen, sf::Vector2f oo);
ostream & operator<<(ostream & screen, sf::Vector2u oo);
bool operator!(sf::Vector2f);