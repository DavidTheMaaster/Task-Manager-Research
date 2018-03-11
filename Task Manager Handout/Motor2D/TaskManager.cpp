#include "TaskManager.h"
#include "j1App.h"
#include "j1Player.h"
#include "j1EntityFactory.h"
#include "j1Input.h"

bool Task::Update(float dt)
{
	bool ret = false;
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		//TODO 3 Pop the first task of the list
	}

	ret = DoTask();

	return ret;
}

bool Task::CleanUp()
{
	return true;
}

bool Task::AddTask(Task * task)
{
	//TODO 3 Add the new task to the list
	return true;
}

bool Task::DoTask()
{
	if (aux_task != nullptr)
	{
	//TODO 3 If the task is finished, pop the next task until the queue is empty
	}
	return true;
}
