//
//  Zebroid.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ZEBROID_H
#define __ZEBROID_H

#include "Horse.h"
#include "Zebra.h"

using namespace std;

class Zebroid : public Horse, public Zebra
{
private:
	Zebroid(const Zebroid& zebroid);
    const Zebroid& operator=(const Zebroid& zebroid);

public:    
	Zebroid(const string& name, float weight, int birthYear, int numOfStrips, float sizeOfHorseShoe);
    
    virtual void toOs(ostream& os) const;
};

#endif /* __ZEBROID_H */