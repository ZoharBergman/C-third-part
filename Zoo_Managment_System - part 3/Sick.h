#ifndef __SICK_H
#define __SICK_H

#include "HealthStatse.h"

class Sick : public HealthStatse
{
public:
	// Methods
	virtual void healthy(Animal& animal) const;
};

#endif // __SICK_H