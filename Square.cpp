#include "Square.h"

bool Square::operator == (const Square& otherSqaure)
{
	if (this->x == otherSqaure.x && this->y == otherSqaure.y)
		return true;

	return false;
}

Square::Square(int x, int y)
{
	this->x = x;
	this->y = y;
}

Square::~Square()
{

}