#include "TaskManager.h"
#include "j1App.h"
#include "j1Player.h"
#include "j1EntityFactory.h"
#include "j1Input.h"

bool Task::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		//TODO
	}

	DoTask();

	return true;
}

bool Task::CleanUp()
{
	return true;
}

bool Task::AddTask(Task * task)
{
	TaskQueue.push(task);
	return true;
}

bool Task::DoTask()
{
	if (aux_task != nullptr)
	{
		if (aux_task->Execute(App->player->Actor))
		{
			if (TaskQueue.size() != 0)
			{
				aux_task = TaskQueue.front();
				TaskQueue.pop();
			}
			else aux_task = nullptr;

		}
	}
	return true;
}
