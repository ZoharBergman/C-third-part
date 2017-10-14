#include "Lion.h"

const char* Lion::MANE_COLOR_TEXT[] = {"White", "Brown", "Yellow", "Red", "Orange"};

Lion::Lion(const string& name, float weight, int birthYear, eManeColor maneColor) :
								Animal(weight, birthYear, name), maneColor(maneColor){}

void Lion::toOs(ostream& os) const
{
	os << ", Mane color: " << MANE_COLOR_TEXT[this->getManeColor()];
}