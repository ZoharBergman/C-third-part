#include "Keeper.h"

const enum Keeper::eAnimal;
const char* Keeper::ANIMALS_NAMES[] = {"Lion", "Penguin", "Elephant", "Giraffe", "Zebra", "Horse", "Zebroid"};

Keeper::Keeper(const string& name, int salary, eAnimal specialty, Area* area) : Worker(name, salary, area), specialty(specialty) {};

void Keeper::toOs(ostream& os) const
{
	os << ", Speciality: " << ANIMALS_NAMES[this->getSpecialty()];
}