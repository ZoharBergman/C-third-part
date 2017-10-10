#include "Keeper.h"

const enum Keeper::eAnimal;
const char* Keeper::eAnimalsNames[] = {"Lion", "Penguin", "Elephant", "Giraffe", "Zebra", "Horse", "Zebroid"};

Keeper::Keeper(const string& name, int salary, eAnimal specialty, Area* area) : Worker(name, salary, area), specialty(specialty) {};

void Keeper::toOs(ostream& os) const
{
	os << ", Speciality: " << eAnimalsNames[this->getSpecialty()];
}