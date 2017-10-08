//
//  Area_Manager.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __AREA_MANAGER_H
#define __AREA_MANAGER_H

#include "Worker.h"

class AreaManager : public Worker
{
private:
	AreaManager(const AreaManager& areaManager);
    const AreaManager& operator=(const AreaManager& areaManager);

public:
	AreaManager(const string& name, int salary, Area* area = nullptr);     
	virtual void setArea(Area* newArea);
};


#endif /* __AREA_MANAGER_H */
