//
//  Animal.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <iostream>

#include "HealthStatse.h"

using namespace std;

class Animal
{
private:
    // Attributes
	string name;
    float weight;
    int birthYear;
	HealthStatse* currentHealthState;

	// Deleted methods
	Animal(const Animal& animal);
    const Animal& operator=(const Animal& animal);
    
public:
	// Ctor & Dtor
	Animal(float weight, int birthYear, const string& name);    
	virtual ~Animal(){ delete currentHealthState; }

	// Getters & Setters
	inline const string& getName() const { return name; }
    inline float getWeight() const { return weight; }
    inline int getBirthYear() const { return birthYear; }
	const HealthStatse* getCurrentHealthState() const { return currentHealthState; }

	void setHealthState(HealthStatse* healthStatse) { this->currentHealthState = healthStatse; }
    
	// Operators
    friend ostream& operator<<(ostream& os, const Animal& animal);

	// Methods
	virtual void toOs(ostream& os) const {};
	void healthy();
	void sick();
};

#endif /* __ANIMAL_H */