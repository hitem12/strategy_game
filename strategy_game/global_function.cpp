#include "global_function.h"

ostream & operator<<(ostream & screen, sf::Vector2f oo)
{
	screen << oo.x << ' ' << oo.y << ' ';
	return screen;
}