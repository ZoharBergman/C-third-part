#include "Keeper.h"

Keeper::Keeper(const string& name, int salary, eAnimal specialty, Area* area) : Worker(name, salary, area), specialty(specialty) {};

ostream& operator<<(ostream& os, const Keeper& keeper)
{
	if (&keeper != nullptr)
	{
		os << (Worker&)keeper << ", Speciality: " << eAnimalsNames[keeper.getSpecialty()].c_str();
	}

	return os;
}