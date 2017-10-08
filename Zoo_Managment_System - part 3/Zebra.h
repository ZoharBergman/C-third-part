//
//  Zibra.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ZEBRA_H
#define __ZEBRA_H

#include "Animal.h"

using namespace std;

class Zebra : virtual public Animal
{
private:
    
    int numOfStrips;
    Zebra(const Zebra& zebra);
    const Zebra& operator=(const Zebra& zebra);

public:
    
	Zebra(const string& name, float weight, int birthYear, int numOfStrips);        
	
	inline int getNumOfStrips() const { return numOfStrips; }
    
    virtual void toOs(ostream& os) const;
};


#endif /* __ZEBRA_H */