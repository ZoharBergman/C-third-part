//
//  main.cpp
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//
#pragma warning( disable : 4290 )
#include <iostream>
#include "Zoo.h"
#include "AreaManager.h"
#include "Veterinarian.h"
#include "Keeper.h"
#include "MaintenanceWorker.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Horse.h"
#include "Lion.h"
#include "Penguin.h"
#include "Zebra.h"
#include "Zebroid.h"

using namespace std;

AreaManager** createAreaManagers(int& numOfManagers);
Area** createAllAreas(AreaManager **managers, int& numOfAreas);
void addAreasToZoo(Zoo& zoo, Area** areas, int& numOfAreas);
Animal** createAnimals(int& numOfAnimals);
void addAllAnimalsToZoo(Zoo& myZoo, Animal** animals, int &numOfAnimals);
Keeper** createAllKeepers(int& numOfKeepers);
void addKeepersToZoo(Zoo& myZoo, Keeper** keepers, int numOfKeepers);
Veterinarian** createAllVeterinarian(int& numOfVeterinarian);
void addAllVeterinarianToZoo(Zoo& myZoo, Veterinarian**vets, int numOfVeterinarian);
void freeAllAreaManagers(AreaManager** areaManagers, int& numOfAreaManagers);
void freeAllAreas(Area** areas, int& numOfAreas);
void freeAllAnimals(Animal** animals, int& numOfAnimals);
void freeAllVeterinarian(Veterinarian** vets, int& numOfVeterinarian);
void freeAllKeepers(Keeper** keepers, int& numOfKeepers);

int main(int argc, const char * argv[]) {

	Zoo* myZoo = Zoo::getInstance();
	int numOfManagers, numOfAreas, numOfKeepers, numOfVeterinarian, numOfAnimals;
	AreaManager** managers;
	Area** areas;
	Keeper** keepers;
	Veterinarian** vets;
	Animal** animals;

	try
	{
		managers = createAreaManagers(numOfManagers);

		areas = createAllAreas(managers, numOfAreas);

		// add all areas
		addAreasToZoo(*myZoo, areas, numOfAreas);

		keepers = createAllKeepers(numOfKeepers);

		// add all the keepers
		addKeepersToZoo(*myZoo, keepers, numOfKeepers);

		vets = createAllVeterinarian(numOfVeterinarian);

		// add all vets
		addAllVeterinarianToZoo(*myZoo, vets, numOfVeterinarian);
		
		animals = createAnimals(numOfAnimals);

		// add animals
		addAllAnimalsToZoo(*myZoo, animals, numOfAnimals);

		// print the whole zoo
		cout << *myZoo << endl;

		cout << "=================================================================" << endl;

		Area* a1 = myZoo->getAllAreas()[0];
		Area* a2 = myZoo->getAllAreas()[1];
		
		cout << "Area A1 before remove animal" << endl;
		cout << *a1 << endl << endl;

		a1->removeAnimal(animals[0]);
		
		cout << "Area A1 after remove animal" << endl;
		cout << *a1 << endl << endl;

		cout << "Is area A1 smaller than area A2? ";
		cout << ((*a1 < *a2 == true) ? "YES" : "NO") << endl << endl;
		
		cout << "Fire the area manager of area A1" << endl;		
		a1->setAreaManager(nullptr);
		cout << *a1 << endl << endl;

		cout << "Try to print the area of the fired area manager" << endl;
		cout << managers[0]->getArea() << endl << endl;

		cout << "Area A2" << endl;
		cout << *a2 << endl << endl;

		cout << "Setting the area manager of A2 to be the area manager of A1" << endl;
		a1->setAreaManager(a2->getAreaManager());
		cout << *a1 << endl << endl;

		cout << "Setting the fired area manager of area A1 to be the area manager of A2" << endl;
		a2->setAreaManager(managers[0]);
		cout << *a2 << endl << endl;

		a1->removeWorker(vets[0]);
		cout << "Area A1 after remove vet" << endl;
		cout << *a1 << endl << endl;

		cout << "Try to remove the vet again" << endl;
		a1->removeWorker(vets[0]);

		// free all memory
		freeAllAnimals(animals, numOfAnimals);
		freeAllAreaManagers(managers, numOfManagers);
		freeAllAreas(areas, numOfAreas);
		freeAllKeepers(keepers, numOfKeepers);
		freeAllVeterinarian(vets, numOfVeterinarian);
	}
	catch (const char* e)
	{
		cout << e;
		
		// free all memory
		freeAllAnimals(animals, numOfAnimals);
		freeAllAreaManagers(managers, numOfManagers);
		freeAllAreas(areas, numOfAreas);
		freeAllKeepers(keepers, numOfKeepers);
		freeAllVeterinarian(vets, numOfVeterinarian);
	}

	return 0;
}

AreaManager** createAreaManagers(int& numOfManagers)
{
	numOfManagers = 3;
	AreaManager** managers = new AreaManager*[numOfManagers];

	managers[0] = new AreaManager("Yogev", 5000);
	managers[1] = new AreaManager("Moshe", 4500);
	managers[2] = new AreaManager("Roie", 4800);

	return managers;
}

Area** createAllAreas(AreaManager **managers, int& numOfAreas)
{
	numOfAreas = 3;
	Area** areas = new Area*[numOfAreas];

	areas[0] = new Area("A1", 4, 4, managers[0]);
	areas[1] = new Area("A2", 4, 4, managers[1]);
	areas[2] = new Area("A3", 4, 4, managers[2]);

	return areas;
}

void addAreasToZoo(Zoo& zoo, Area** areas, int& numOfAreas)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		zoo += *areas[i];
	}
}

Animal** createAnimals(int& numOfAnimals)
{
	numOfAnimals = 4;
	Animal** animals = new Animal*[numOfAnimals];

	animals[0] = new Horse("Horsy", 208.5f, 1998, 40.2f);
	animals[1] = new Penguin("Pini", 1.2f, 2005, Penguin::eSeaFood::CRAB);
	animals[2] = new Elephant("Eli", 2.5f, 2003, 1.35f, 2.75f);
	animals[3] = new Zebroid("Zeze", 1.45f, 2010, 128, 38.6f);
	
	return animals;
}

void addAllAnimalsToZoo(Zoo& myZoo, Animal** animals, int &numOfAnimals)
{
	for (int i = 0; i < numOfAnimals - 1; i++)
	{
		myZoo.addAnimal(*animals[i], myZoo.getAllAreas()[i]->getName().c_str());
	}

	// another animal to the last area
	myZoo.addAnimal(*animals[3], myZoo.getAllAreas()[2]->getName().c_str());
}

Keeper** createAllKeepers(int& numOfKeepers)
{
	numOfKeepers = 3;
	Keeper** keepers = new Keeper*[numOfKeepers];

	keepers[0] = new Keeper("Kipi", 7500, Keeper::eAnimal::PENGUIN);
	keepers[1] = new Keeper("Keepi", 7500, Keeper::eAnimal::ELEPHANT);
	keepers[2] = new Keeper("Keepee", 7500, Keeper::eAnimal::HORSE);

	return keepers;
}

void addKeepersToZoo(Zoo& myZoo, Keeper** keepers, int numOfKeepers)
{
	for (int i = 0; i < numOfKeepers; i++)
	{
		myZoo.addWorker(*keepers[i], myZoo.getAllAreas()[i]->getName().c_str());
	}
}

Veterinarian** createAllVeterinarian(int& numOfVeterinarian)
{
	numOfVeterinarian = 3;
	Veterinarian** vets = new Veterinarian*[numOfVeterinarian];

	vets[0] = new Veterinarian("Vivi", 10000, 5);
	vets[1] = new Veterinarian("Vuvu", 10000, 8);
	vets[2] = new Veterinarian("Kobi", 10000, 10);

	return vets;
}

void addAllVeterinarianToZoo(Zoo& myZoo, Veterinarian**vets, int numOfVeterinarian)
{
	for (int i = 0; i < numOfVeterinarian; i++)
	{
		myZoo.addWorker(*vets[i], myZoo.getAllAreas()[i]->getName().c_str());
	}
}

void freeAllAreaManagers(AreaManager** areaManagers, int& numOfAreaManagers)
{
	for (int i = 0; i < numOfAreaManagers; i++)
	{
		delete areaManagers[i];
	}

	delete[]areaManagers;
}

void freeAllAreas(Area** areas, int& numOfAreas)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		delete areas[i];
	}

	delete[]areas;
}

void freeAllAnimals(Animal** animals, int& numOfAnimals)
{
	for (int i = 0; i < numOfAnimals; i++)
	{
		delete animals[i];
	}

	delete[]animals;
}

void freeAllVeterinarian(Veterinarian** vets, int& numOfVeterinarian)
{
	for (int i = 0; i < numOfVeterinarian; i++)
	{
		delete vets[i];
	}

	delete[]vets;
}

void freeAllKeepers(Keeper** keepers, int& numOfKeepers)
{
	for (int i = 0; i < numOfKeepers; i++)
	{
		delete keepers[i];
	}

	delete[]keepers;
}