#include "Zebroid.h"

Zebroid::Zebroid(const string& name, float weight, int birthYear, int numOfStrips, float sizeOfHorseShoe) : 
	Animal(weight, birthYear, name), Horse(name, weight, birthYear, sizeOfHorseShoe), Zebra(name, weight, birthYear, numOfStrips){}

void Zebroid::toOs(ostream& os) const
{
	this->Zebra::toOs(os);
	this->Horse::toOs(os);	
}