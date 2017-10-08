//
//  Penguin.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __PENGUIN_H
#define __PENGUIN_H

#include "Animal.h"

using namespace std;

static const enum eSeaFood { SHRIMP, CRAB, FISH, CALAMARI };
static const string eSeaFoodText[] = {"Shrimp", "Crab", "Fish", "Calamari"};

class Penguin : public Animal
{
private:
    
    eSeaFood favoriteFood;
    Penguin(const Penguin& penguin);
    const Penguin& operator=(const Penguin& penguin);

public:
    
	Penguin(const string& name, float weight, int birthYear, eSeaFood favoriteFood);        
    
	inline eSeaFood getFavoriteFood() const { return favoriteFood; }
	void setFavoriteFood(eSeaFood favoriteFood) { this->favoriteFood = favoriteFood; }
    
    virtual void toOs(ostream& os) const;
    
};


#endif /* __PENGUIN_H */