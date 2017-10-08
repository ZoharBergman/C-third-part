#include "Animal.h"

Animal::Animal(float weight, int birthYear, const string& name) : name(name), weight(weight), birthYear(birthYear){}

ostream& operator<<(ostream& os, const Animal& animal)
{
	if (&animal != nullptr)
	{
		os << "Name: " << animal.getName().c_str() << ", Weight: " << animal.getWeight() << ", Birth year: " << animal.getBirthYear();
		animal.toOs(os);
	}

	return os;
}