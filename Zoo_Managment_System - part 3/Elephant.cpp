#include "Elephant.h"

Elephant::Elephant(const string& name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk) : 
	Animal(weight, birthYear, name), sizeOfEars(sizeOfEars), lengthOfTrunk(lengthOfTrunk){}

void Elephant::toOs(ostream& os) const
{
	os << ", Size of ears: " << this->getSizeOfEars() << ", Length of trunk: " << this->getLengthOfTrunk();
}