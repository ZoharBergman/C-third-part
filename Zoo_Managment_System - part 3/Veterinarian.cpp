#include "Veterinarian.h"

Veterinarian::Veterinarian(const string& name, int salary, int yearsOfExperience, Area* area) : 
	Worker(name, salary, area), yearsOfExperience(yearsOfExperience){};

ostream& operator<<(ostream& os, const Veterinarian& veterinarian)
{
	if (&veterinarian != nullptr)
	{
		os << (Worker&)veterinarian << ", Years of experience: " << veterinarian.getYearsOfExperience();
	}

	return os;
}