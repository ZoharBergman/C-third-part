//
//  Area.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __AREA_H
#define __AREA_H

#include <iostream>
#include <vector>

#include "AreaManager.h"
#include "Worker.h"
#include "Animal.h"

//class Animal;
using namespace std;

class Area
{

private:
	string name;
	int maxNumberOfAnimals;
	int maxNumberOfWorkers;
	AreaManager* areaManager;
	vector<Animal*> animals;
	vector<Worker*> workers;

	Area(const Area& area);
	//const Area& operator=(const Area& area);

public:

	Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager* areaManager = nullptr);

	inline const string& getName() const { return name; }

	inline long getNumOfAnimals() const { return animals.size(); }
	inline long getMaxNumberOfAnimals() const { return maxNumberOfAnimals; }

	inline long getNumOfWorkers() const { return workers.size(); }
	inline long getMaxNumberOfWorkers() const { return maxNumberOfWorkers; }

	inline const AreaManager* getAreaManager() const { return areaManager; }
	inline AreaManager* getAreaManager() { return areaManager; }
	void setAreaManager(AreaManager* areaManager);

	void addAnimal(Animal* animal) throw (const char*);
	void addWorker(Worker* worker) throw (const char*);

	void removeAnimal(const Animal* animal) throw (const char*);
	void removeWorker(Worker* worker) throw (const char*);

	const vector<Animal*> getAllAnimals() const { return animals; }
	const vector<Worker*> getAllworkers() const { return workers; }

	vector<Animal*> getAllAnimals() { return animals; }
	vector<Worker*> getAllworkers() { return workers; }

	const Area& operator+=(Animal* animal) throw (const char*) { addAnimal(animal); return *this; }

	bool operator<(const Area& other) const { return this->getMaxNumberOfAnimals() < other.getMaxNumberOfAnimals(); }

	bool operator>(const Area& other) const { return this->getMaxNumberOfAnimals() > other.getMaxNumberOfAnimals(); }

	bool operator==(const Area& other) const { return this->getName().compare(other.getName()) == 0; }

	friend ostream& operator<<(ostream& os, const Area& area);

private:
	vector<Worker*>::iterator isWorkerExists(const Worker* worker);
	vector<Animal*>::iterator isAnimalExists(const Animal* animal);
};


#endif /* __AREA_H */
