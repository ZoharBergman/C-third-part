//
//  Giraffe.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __GIRAFFE_H
#define __GIRAFFE_H

#include "Animal.h"

using namespace std;

class Giraffe : public Animal
{
private:
	// Attributes
    float lengthOfNeck;
    
	// Deleted methods
	Giraffe(const Giraffe& giraffe);
    const Giraffe& operator=(const Giraffe& giraffe);

public:
	// Ctor
	Giraffe(const string& name, float weight, int birthYear, float lengthOfNeck);
    
	// Getters
	inline float getLengthOfNeck() const { return lengthOfNeck; }
    
	// Methods
    virtual void toOs(ostream& os) const;    
};

#endif /* __GIRAFFE_H */