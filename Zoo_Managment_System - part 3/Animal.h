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

using namespace std;

class Animal
{
    
private:
    string name;
    float weight;
    int birthYear;
	Animal(const Animal& animal);
    const Animal& operator=(const Animal& animal);
    
public:
	Animal(float weight, int birthYear, const string& name = nullptr);
    
	virtual ~Animal(){}

	inline const string& getName() const { return name; }
    
	inline float getWeight() const { return weight; }
    
	inline int getBirthYear() const { return birthYear; }
    
    friend ostream& operator<<(ostream& os, const Animal& animal);

	virtual void toOs(ostream& os) const {};
};

#endif /* __ANIMAL_H */