#include "Horse.h"

Horse::Horse(const string& name, float weight, int birthYear, float sizeOfHorseShoe) : 
						Animal(weight, birthYear, name), sizeOfHorseShoe(sizeOfHorseShoe){}

void Horse::toOs(ostream& os) const
{
	os << ", Size of horse shoe: " << this->getSizeOfHorseShoe();
}