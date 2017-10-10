#include "Zoo.h"

Zoo Zoo::theZoo;

Zoo::Zoo(const string& name, int maxNumOfAreas) : name(name), maxNumOfAreas(maxNumOfAreas){}

void Zoo::addArea(Area& area) throw (const char*)
{
	if (getNumOfAreas() < maxNumOfAreas)
	{
		areas.push_back(&area);
	}
	else
	{
		throw "The number of areas in this zoo is max";
	}
}

void Zoo::addAnimal(Animal& animal, const string& areaName) throw (const char*)
{
	vector<Area*>::const_iterator areaIndex = getAreaIndexByName(areaName);

	if (areaIndex != areas.end())
	{
		(*areaIndex)->addAnimal(&animal);
	}
	else
	{
		throw "This area name does not exists in this zoo";
	}
}

void Zoo::addWorker(Worker& worker, const string& areaName) throw (const char*)
{
	vector<Area*>::const_iterator areaIndex = getAreaIndexByName(areaName);

	if (areaIndex != areas.end())
	{
		(*areaIndex)->addWorker(&worker);
	}
	else
	{
		throw "This area name does not exists in this zoo";
	}
}

ostream& operator<<(ostream& os, const Zoo& zoo)
{
	if (&zoo != nullptr)
	{
		os << "Name: " << zoo.getName().c_str() << endl << "Max number of areas: " << zoo.getMaxNumOfAreas()
			<< endl << "Number of areas: " << zoo.getNumOfAreas() << endl << "Areas: " << endl;

		const vector<Area*> areas = zoo.getAllAreas();

		for (vector<Area*>::const_iterator itr = areas.begin(); itr < areas.end(); ++itr)
		{
			os << "{" << **itr << "}";

			if (itr < areas.end() - 1)
				os << "," << endl;
		}
	}

	return os;
}

vector<Area*>::const_iterator Zoo::getAreaIndexByName(const string& name) const
{
	for (vector<Area*>::const_iterator itr = areas.begin(); itr < areas.end(); ++ itr)
	{
		if ((*itr)->getName().compare(name) == 0)
		{
			return itr;
		}
	}

	return areas.end();
}