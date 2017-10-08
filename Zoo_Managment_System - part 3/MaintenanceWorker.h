//
//  Maintenance_Worker.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __MAINTENANCE_WORKER_H
#define __MAINTENANCE_WORKER_H

#include "Worker.h"

class MaintenanceWorker : public Worker
{
private:
	MaintenanceWorker(const MaintenanceWorker& maintenanceWorker);
    const MaintenanceWorker& operator=(const MaintenanceWorker& maintenanceWorker);

public:
	MaintenanceWorker(const string& name, int salary, Area* area = nullptr);       
    
};


#endif /* __MAINTENANCE_WORKER_H */