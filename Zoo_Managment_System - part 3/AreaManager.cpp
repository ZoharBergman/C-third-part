#include "AreaManager.h"
#include "Area.h"

AreaManager::AreaManager(const string& name, int salary, Area* area) : Worker(name, salary, area) {}

void AreaManager::setArea(Area* newArea)
{
	// Checking that the areas are different
	if(area != newArea)
	{
		// Setting the area of this area manager to the new area
		area = newArea;

		// In case the new area is not null , we should add to it this area manager
		if (area != nullptr)
		{
			area->setAreaManager(this);
		}
	}
}