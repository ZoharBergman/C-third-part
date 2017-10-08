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

using namespace std;

class Area;

class Worker
{
protected:	
	static long idCounter;
	string name;
    long idNumber;
    int salary;
	Area* area;
    Worker(const Worker& worker);
    const Worker& operator=(const Worker& worker);

public:
    
	Worker(const string& name, int salary, Area* area = nullptr);
	
	inline const string& getName() const { return name; }
    
	inline long getIdNumber() const { return idNumber; }
    
	inline int getSalary() const { return salary; }
	void setSalary(int salary) { this->salary = salary; }
    
	inline const Area& getArea() const { return *area; }
	inline Area& getArea() { return *area; }
	virtual void setArea(Area* newArea);
    
    friend ostream& operator<<(ostream& os, const Worker& worker);
    
};

#endif /* __WORKER_H */