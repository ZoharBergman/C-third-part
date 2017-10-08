#include "Area.h"

Area::Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager* areaManager) :
	name(name), maxNumberOfAnimals(maxNumberOfAnimals), maxNumberOfWorkers(maxNumberOfWorkers), areaManager(nullptr), numOfAnimals(0)
{
	setAreaManager(areaManager);
}

void Area::setAreaManager(AreaManager* newAreaManager)
{
	if (areaManager != newAreaManager)
	{
		if (areaManager != nullptr)
		{
			areaManager->setArea(nullptr);
		}

		areaManager = newAreaManager;

		if (areaManager != nullptr)
		{
			areaManager->setArea(this);
		}
	}
}

void Area::addAnimal(Animal* animal) throw (const char *)
{
	// Checking that there is enough place for another animal
	if (getNumOfAnimals() < maxNumberOfAnimals)
	{
		// Checking that the animal does not exists in this area
		if (animal != nullptr && !isAnimalExists(animal))
		{
			animals.addData(animal);
			numOfAnimals++;
		}
	}
	else
	{
		throw "The number of animals in this area is the max";
	}
}

void Area::addWorker(Worker* worker) throw (const char *)
{
	// Checking that there is enough place for another wotker
	if (getNumOfWorkers() < maxNumberOfWorkers)
	{
		// Checking that the worker does not exists in this area
		if (worker != nullptr && isWorkerExists(worker) == workers.end())
		{
			workers.push_back(worker);
			worker->setArea(this);
		}
	}
	else
	{
		throw "The number of workers in this area is the max";
	}
}

void Area::removeAnimal(Animal* animal) throw (const char *)
{
	if (animal != nullptr)
	{
		// In case the animal exists, we should erase it from the vector of animals
		if(isAnimalExists(animal))
		{
			animals.removeData(animal);
			numOfAnimals--;
		}
		else
		{
			throw "This animal does not exists in this area";
		}
	}
}

void Area::removeWorker(Worker* worker) throw (const char *)
{
	if (worker != nullptr)
	{
		vector<Worker*>::const_iterator itr = isWorkerExists(worker);

		// In case the worker exists, we should remove it from the cevtor of workers
		if(itr != workers.end())
		{
			worker->setArea(nullptr);
			workers.erase(itr);
		}
		else
		{
			throw "This worker does not exists in this area";
		}
	}
}

vector<Worker*>::const_iterator Area::isWorkerExists(const Worker* worker) const
{
	return find(workers.begin(), workers.end(), worker);
}

bool Area::isAnimalExists(Animal* animal) const
{
	return animals.isExists(animal);
}

ostream& operator<<(ostream& os, const Area& area)
{
	if (&area != nullptr)
	{
		os << "Name: " << area.getName().c_str() << ", Max number of animals: " << area.getMaxNumberOfAnimals() 
		   << ", Number of animals: " << area.getNumOfAnimals() << ", Max number of workers: " << area.getMaxNumberOfWorkers() 
		   << ", Number of workers: " << area.getNumOfWorkers() << ", Area manager: {" << *area.getAreaManager() << "}, Animals: {";
		   //<< area.getAllAnimals() << "}, Workers: {";
		const LinkedList<Animal*>& animals = area.getAllAnimals();
		const vector<Worker*> workers = area.getAllworkers();

		for (vector<Worker*>::const_iterator itr = workers.begin(); itr < workers.end(); ++itr)
		{
			os << "{" << **itr << "}, ";
		}

		os << '\b' << '\b';

		os << "}";
	}

	return os;
}