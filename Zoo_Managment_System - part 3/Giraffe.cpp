#include "Giraffe.h"

Giraffe::Giraffe(const string& name, float weight, int birthYear, float lengthOfNeck) :
								Animal(weight, birthYear, name), lengthOfNeck(lengthOfNeck){}

void Giraffe::toOs(ostream& os) const
{
	os << ", Length of neck: " << this->getLengthOfNeck();
}