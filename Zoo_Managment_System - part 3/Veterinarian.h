//
//  Veterinarian.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __VETERINARIAN_H
#define __VETERINARIAN_H

#include "Worker.h"

class Veterinarian : public Worker
{
private:
    int yearsOfExperience;
	Veterinarian(const Veterinarian& veterinarian);
    const Veterinarian& operator=(const Veterinarian& veterinarian);

public:
    Veterinarian(const string& name, int salary, int yearsOfExperience, Area* area = nullptr);       
    
	inline int getYearsOfExperience() const { return yearsOfExperience; }
    
    friend ostream& operator<<(ostream& os, const Veterinarian& veterinarian);
    
};

#endif /* __VETERINARIAN_H */