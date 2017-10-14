#include "Penguin.h"

const char* Penguin::SEA_FOOD_TEXT[] = {"Shrimp", "Crab", "Fish", "Calamari"};

Penguin::Penguin(const string& name, float weight, int birthYear, eSeaFood favoriteFood) : 
									Animal(weight, birthYear, name), favoriteFood(favoriteFood){}

void Penguin::toOs(ostream& os) const
{
	os << ", Favorite food: " << SEA_FOOD_TEXT[this->getFavoriteFood()];
}