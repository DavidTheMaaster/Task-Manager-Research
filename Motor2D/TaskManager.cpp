#include "TaskManager.h"
#include "j1App.h"
#include "j1Player.h"
#include "j1EntityFactory.h"
#include "j1Input.h"

bool MoveLeft::Execute(Entity* actor)
{
	bool ret = false;
	if (actor->pos.x == App->player->posaux.x - 32)
	{
		App->player->posaux.x = actor->pos.x;

		ret = true;
	}
	else
	{
		actor->pos.x -= App->player->speed.x;
	}
	return ret;
}

bool MoveRight::Execute(Entity* actor)
{
	bool ret = false;
	if (actor->pos.x == App->player->posaux.x + 32)
	{
		App->player->posaux.x = actor->pos.x;
		
		ret = true;
	}
	else
	{
		actor->pos.x += App->player->speed.x;
	}
	return ret;
}

bool MoveForward::Execute(Entity* actor)
{
	bool ret = false;
	if (actor->pos.y == App->player->posaux.y - 32)
	{
		App->player->posaux.y = actor->pos.y;

		ret = true;
	}
	else
	{
		actor->pos.y -= App->player->speed.y;
	}
	return ret;
}

bool MoveBackWard::Execute(Entity* actor)
{
	bool ret = false;
	if (actor->pos.y == App->player->posaux.y + 32)
	{
		App->player->posaux.y = actor->pos.y;
		
		ret = true;
	}
	else
	{
		actor->pos.y += App->player->speed.y;
	}
	return ret;
}

bool Task::Update(float dt)
{
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		if (aux_task == nullptr && TaskQueue.size() != 0)
		{
			aux_task = TaskQueue.front();
			TaskQueue.pop();
		}
	}

	DoTask();

	return true;
}

bool Task::CleanUp()
{
	while (TaskQueue.size() != 0)
	{
		TaskQueue.pop();
	}
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
