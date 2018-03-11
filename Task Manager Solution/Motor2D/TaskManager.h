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
	~Task() {};

	virtual bool Execute(Entity* actor) { return true; };

	bool Update(float dt);
	bool CleanUp();

	bool AddTask(Task* task);
	bool DoTask();

private:
	//TODO 1 Create a queue of tasks
	std::queue<Task*> TaskQueue;
	
public:
	Task * aux_task = nullptr;
};


class MoveLeft : public Task
{
public:
	MoveLeft() {};
	~MoveLeft() {};

	bool Execute(Entity* actor);
};
//TODO 2 Create a class for each task you want to do (one for each direction)
//TODO 6 Add the parameter "Actor" to all Execute() functions 

class MoveRight : public Task
{
public:
	MoveRight() {};
	~MoveRight() {};

	bool Execute(Entity* actor);
};

class MoveForward : public Task
{
public:
	MoveForward() {};
	~MoveForward() {};

	bool Execute(Entity* actor);
};

class MoveBackWard : public Task
{
public:
	MoveBackWard() {};
	~MoveBackWard() {};

	bool Execute(Entity* actor);
};
#endif // !_TASKMANAGER_H__

