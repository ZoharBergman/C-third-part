#include "Sick.h"
#include "Healthy.h"
#include "Animal.h"

void Sick::healthy(Animal& animal) const 
{ 
	animal.setHealthState(new Healthy()); 
	delete this; 
}
