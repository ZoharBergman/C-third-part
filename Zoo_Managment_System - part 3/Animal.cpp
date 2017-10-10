#include "Animal.h"
#include "Healthy.h"

Animal::Animal(float weight, int birthYear, const string& name) : 
	name(name), weight(weight), birthYear(birthYear), currentHealthState(new Healthy()){}

ostream& operator<<(ostream& os, const Animal& animal)
{
	if (&animal != nullptr)
	{
		os << typeid(animal).name()+6 << "--> Name: " << animal.getName().c_str() << ", Weight: " << animal.getWeight() 
			<< ", Birth year: " << animal.getBirthYear() << ", Health state: " << typeid(*animal.getCurrentHealthState()).name()+6;
		animal.toOs(os);
	}

	return os;
}

void Animal::healthy()
{
	currentHealthState->healthy(*this);
}

void Animal::sick()
{
	currentHealthState->sick(*this);
}