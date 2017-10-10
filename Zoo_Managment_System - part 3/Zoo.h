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
    // Attributes
    string name;
    int maxNumOfAreas;
    vector<Area*> areas;

	// Static attributes
	static Zoo theZoo;

	// Deleted methods
	Zoo(const Zoo* other);
	const Zoo& operator=(const Zoo& other);
	
	// Ctor
	Zoo(const string& name = "My Zoo", int maxNumOfAreas = 10);

public:
    // Getters
	static Zoo* getInstance() { return &theZoo; }
    inline const string& getName() const { return name; }
    inline int getMaxNumOfAreas() const { return maxNumOfAreas; }
	int getNumOfAreas() const { return areas.size(); }
    const vector<Area*> getAllAreas() const { return areas; }
	vector<Area*> getAllAreas() { return areas; }

	// Methods
    void addArea(Area& area) throw (const char *);
    void addAnimal(Animal& animal, const string& areaName) throw (const char *);
    void addWorker(Worker& worker, const string& areaName) throw (const char *);
    
	// Operators
	const Zoo& operator+=(Area& area) throw (const char *) { addArea(area); return *this; }
    const Area& operator[](int index) const { return *areas[index]; }
    friend ostream& operator<<(ostream& os, const Zoo& zoo);	

private:
	// Methods
	vector<Area*>::const_iterator getAreaIndexByName(const string& name) const;
};

#endif /* __ZOO_H */