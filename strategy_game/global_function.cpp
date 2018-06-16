#include "global_function.h"

ostream & operator<<(ostream & screen, sf::Vector2f oo)
{
	screen << oo.x << ' ' << oo.y << ' ';
	return screen;
}

ostream & operator<<(ostream & screen, sf::Vector2u oo)
{
	screen << oo.x << ' ' << oo.y << ' ';
	return screen;
}

bool operator!(sf::Vector2f vec)
{
	if (vec == sf::Vector2f(0, 0))
		return true;
	else
		return false;
}
