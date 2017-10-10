#include "Lion.h"

const char* Lion::eManeColorText[] = {"White", "Brown", "Yellow", "Red", "Orange"};

Lion::Lion(const string& name, float weight, int birthYear, eManeColor maneColor) :
								Animal(weight, birthYear, name), maneColor(maneColor){}

void Lion::toOs(ostream& os) const
{
	os << ", Mane color: " << eManeColorText[this->getManeColor()];
}