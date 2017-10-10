#ifndef __HEALTHY_H
#define __HEALTHY_H

#include "HealthStatse.h"

class Healthy : public HealthStatse
{
public:
	// Methods
	virtual void sick(Animal& animal) const;
};

#endif // __HEALTHY_H