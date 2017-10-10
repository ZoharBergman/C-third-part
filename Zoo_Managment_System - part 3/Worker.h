//
//  Worker.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __WORKER_H
#define __WORKER_H

#include <iostream>

#include "WorkerObserver.h"

using namespace std;

class Area;

class Worker : public WorkerObserver
{
protected:	
	// Attributes
	static long idCounter;
	string name;
	long idNumber;
	int salary;
	Area* area;

	// Deleted methods
	Worker(const Worker& worker);
	const Worker& operator=(const Worker& worker);

public:
	// Ctor
	Worker(const string& name, int salary, Area* area = nullptr);

	// Getters & Setters
	inline const string& getName() const { return name; }
	inline long getIdNumber() const { return idNumber; }
	inline int getSalary() const { return salary; }
	inline const Area& getArea() const { return *area; }
	inline Area& getArea() { return *area; }

	void setSalary(int salary) { this->salary = salary; }
	virtual void setArea(Area* newArea);

	// Operators
	friend ostream& operator<<(ostream& os, const Worker& worker);

	// Methods
	virtual void checkAnimalHealth(Animal& animal) const;
	virtual void toOs(ostream& os) const {};
};

#endif /* __WORKER_H */