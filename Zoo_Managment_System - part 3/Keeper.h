//
//  Keeper.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __KEEPER_H
#define __KEEPER_H

#include "Worker.h"

const static int ANIMALS_SIZE = 7;
const static enum eAnimal {LION, PENGUIN, ELEPHANT, GIRAFFE, ZEBRA, HORSE, ZEBROID};
const static string eAnimalsNames[ANIMALS_SIZE] = {"Lion", "Penguin", "Elephant", "Giraffe", "Zebra", "Horse", "Zebroid"};

class Keeper : public Worker
{
private:
	eAnimal specialty;
	Keeper(const Keeper& keeper);
	const Keeper& operator=(const Keeper& keeper);

public:
	Keeper(const string& name, int salary, eAnimal specialty, Area* area = nullptr);	

	inline eAnimal getSpecialty() const { return specialty; }

	friend ostream& operator<<(ostream& os, const Keeper& keeper);
};


#endif /* __KEEPER_H */