#ifndef _TASKMANAGER_H__
#define _TASKMANAGER_H__

#include "p2Point.h"
#include <queue>
#include "j1Module.h"

class Entity;

class Task: public j1Module
{
public:
	Task() {};
	virtual ~Task() {};

	virtual bool Execute(Entity* actor) { return true; };

	bool Update(float dt);
	bool CleanUp();

	bool AddTask(Task* task);
	bool DoTask();

private:
	//TODO 1 Create a queue of tasks
	
public:
	Task * aux_task = nullptr;
};

//TODO 2 Create a class for each task you want to do (one for each direction)
//TODO 6 Add the parameter "Actor" to all Execute() functions 


#endif // !_TASKMANAGER_H__

