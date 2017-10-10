//
//  Area.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __AREA_H
#define __AREA_H
#pragma warning( disable : 4290 )

#include <iostream>
#include <vector>

#include "AreaManager.h"
#include "Worker.h"
#include "Animal.h"
#include "LinkedList.h"

using namespace std;

class Area
{
private:
	// Attributes
	string name;
	int numOfAnimals;
	int maxNumberOfAnimals;
	int maxNumberOfWorkers;
	AreaManager* areaManager;
	LinkedList<Animal*> animals;	
	vector<Worker*> workers;
	
	// Deleted methods
	Area(const Area& area);
	const Area& operator=(const Area& area);

public:
	// Ctor
	Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager* areaManager = nullptr);

	// Getters & Setters
	inline const string& getName() const { return name; }
	inline long getNumOfAnimals() const { return numOfAnimals; }
	inline long getMaxNumberOfAnimals() const { return maxNumberOfAnimals; }
	inline long getNumOfWorkers() const { return workers.size(); }
	inline long getMaxNumberOfWorkers() const { return maxNumberOfWorkers; }
	inline const AreaManager* getAreaManager() const { return areaManager; }
	inline AreaManager* getAreaManager() { return areaManager; }
	const LinkedList<Animal*>& getAllAnimals() const { return animals; }
	LinkedList<Animal*>& getAllAnimals() { return animals; }
	const vector<Worker*>& getAllworkers() const { return workers; }	
	vector<Worker*>& getAllworkers() { return workers; }

	void setAreaManager(AreaManager* areaManager);

	// Methods
	void addAnimal(Animal* animal) throw (const char*);
	void addWorker(Worker* worker) throw (const char*);
	void removeAnimal(Animal* animal) throw (const char*);
	void removeWorker(Worker* worker) throw (const char*);
	void notifyAllWorkers(Animal& animal) const;

	// Operators
	const Area& operator+=(Animal* animal) throw (const char*) { addAnimal(animal); return *this; }
	bool operator<(const Area& other) const { return this->getMaxNumberOfAnimals() < other.getMaxNumberOfAnimals(); }
	bool operator>(const Area& other) const { return this->getMaxNumberOfAnimals() > other.getMaxNumberOfAnimals(); }
	bool operator==(const Area& other) const { return this->getName().compare(other.getName()) == 0; }
	friend ostream& operator<<(ostream& os, const Area& area);
	
private:
	// Methods
	vector<Worker*>::const_iterator isWorkerExists(const Worker* worker) const;
	bool isAnimalExists(Animal* animal) const;
};

#endif /* __AREA_H */
