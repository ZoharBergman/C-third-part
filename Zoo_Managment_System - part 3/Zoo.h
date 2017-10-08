//
//  Zoo.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 18/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ZOO_H
#define __ZOO_H

#include "Area.h"
#include "Worker.h"
#include "Animal.h"

using namespace std;

class Zoo
{
private:
    
    string name;
    int maxNumOfAreas;
    vector<Area*> areas;

public:
    
    Zoo(const string& name, int maxNumOfAreas);
    
	const string& getName() const { return name; }
    
	int getMaxNumOfAreas() const { return maxNumOfAreas; }
	int getNumOfAreas() const { return areas.size(); }
    
    void addArea(Area& area) throw (const char *);
    
    void addAnimal(Animal& animal, const string& areaName) throw (const char *);
    
    void addWorker(Worker& worker, const string& areaName) throw (const char *);
    
	const vector<Area*> getAllAreas() const { return areas; }
	vector<Area*> getAllAreas() { return areas; }
    
	const Zoo& operator+(Area& area) throw (const char *) { addArea(area); return *this; }
    
	const Area& operator[](int index) const { return *areas[index]; }
    
    friend ostream& operator<<(ostream& os, const Zoo& zoo);	

private:
	vector<Area*>::const_iterator getAreaIndexByName(const string& name) const;
};


#endif /* __ZOO_H */