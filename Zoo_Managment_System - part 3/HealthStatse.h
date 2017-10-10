#ifndef __HEALTH_STATE_H
#define __HEALTH_STATE_H

class Animal;

class HealthStatse
{
public:
	// Methods
	virtual void healthy(Animal& animal) const {}
	virtual void sick(Animal& animal) const {}
};

#endif // __HEALTH_STATE_H