#include "Area.h"

Area::Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager* areaManager) :
	name(name), maxNumberOfAnimals(maxNumberOfAnimals), maxNumberOfWorkers(maxNumberOfWorkers), 
	numOfAnimals(0), numOfWorkers(0), areaManager(nullptr)
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
	if (numOfAnimals < maxNumberOfAnimals)
	{
		// Checking that the animal does not exists in this area
		if (animal != nullptr && isAnimalExists(animal) == animals.end())
		{
			animals.push_back(animal);
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
	if (numOfWorkers < maxNumberOfWorkers)
	{
		// Checking that the worker does not exists in this area
		if (worker != nullptr && isWorkerExists(worker) == workers.end())
		{
			workers.push_back(worker);
			numOfWorkers++;
			worker->setArea(this);
		}
	}
	else
	{
		throw "The number of workers in this area is the max";
	}
}

void Area::removeAnimal(const Animal* animal) throw (const char *)
{
	if (animal != nullptr)
	{
		vector<Animal*>::iterator itr = isAnimalExists(animal);

		// In case the animal exists, we should erase it from the vector of animals
		if(itr != animals.end())
		{
			animals.erase(itr);
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
		vector<Worker*>::iterator itr = isWorkerExists(worker);

		// In case the worker exists, we should remove it from the cevtor of workers
		if(itr != workers.end())
		{
			worker->setArea(nullptr);
			workers.erase(itr);
			numOfWorkers--;
		}
		else
		{
			throw "This worker does not exists in this area";
		}
	}
}

vector<Worker*>::iterator Area::isWorkerExists(const Worker* worker)
{
	return find(workers.begin(), workers.end(), worker);
}

vector<Animal*>::iterator Area::isAnimalExists(const Animal* animal)
{
	return find(animals.begin(), animals.end(), animal);
}

ostream& operator<<(ostream& os, const Area& area)
{
	if (&area != nullptr)
	{
		os << "Name: " << area.getName().c_str() << ", Max number of animals: " << area.getMaxNumberOfAnimals() << ", Number of animals: " << area.getNumOfAnimals()
			<< ", Max number of workers: " << area.getMaxNumberOfWorkers() << ", Number of workers: " << area.getNumOfWorkers() << ", Area manager: {" << *area.getAreaManager() << "}, Animals: {";

		const vector<Animal*> animals = area.getAllAnimals();

		for (vector<Animal*>::const_iterator itr = animals.begin(); itr < animals.end(); ++itr)
		{
			os << "{" << **itr << "}, ";
		}

		os << '\b' << '\b';

		os << "}, Workers: {";

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