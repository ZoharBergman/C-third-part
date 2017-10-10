	//
//  Donkey.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __HOURSE_H
#define __HOURSE_H

#include "Animal.h"

using namespace std;

class Horse : virtual public Animal
{
private:
	// Attributes
    float sizeOfHorseShoe;
 
	// Deleted methods
	Horse(const Horse& horse);
    const Horse& operator=(const Horse& horse);

public:
	// Ctor
	Horse(const string& name, float weight, int birthYear, float sizeOfHorseShoe);        
    
	// Getters
	inline float getSizeOfHorseShoe() const { return sizeOfHorseShoe; }
    
	// Methods
    virtual void toOs(ostream& os) const;
};

#endif /* __HOURSE_H */