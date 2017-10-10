#include "Healthy.h"
#include "Sick.h"
#include "Animal.h"

void Healthy::sick(Animal& animal) const 
{ 
	animal.setHealthState(new Sick()); 
	delete this; 
}