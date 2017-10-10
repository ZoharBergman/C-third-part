#ifndef __WORKER_OBSERVER_H
#define __WORKER_OBSERVER_H

#include "Animal.h"

class WorkerObserver
{
public:
	// Methods
	virtual void checkAnimalHealth(Animal& animal) const = 0;
};

#endif // __WORKER_OBSERVER_H