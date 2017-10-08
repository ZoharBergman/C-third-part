//
//  Elephant.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ELEPHANT_H
#define __ELEPHANT_H

#include "Animal.h"
#include "Area.h"

using namespace std;

class Elephant : public Animal
{

private:
    
    float sizeOfEars;
    float lengthOfTrunk;
    Elephant(const Elephant& elephant);
    const Elephant& operator=(const Elephant& elephant);

public:
    
	Elephant(const string& name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk);
    
	inline float getSizeOfEars() const { return sizeOfEars; }
	inline float getLengthOfTrunk() const { return lengthOfTrunk; }
    
	virtual void toOs(ostream& os) const;    
    
};

#endif /* __ELEPHANT_H */