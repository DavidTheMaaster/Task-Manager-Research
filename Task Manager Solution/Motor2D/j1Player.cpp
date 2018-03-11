#include "j1Player.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "j1Map.h"
#include "j1EntityFactory.h"
#include "TaskManager.h"

j1Player::j1Player() : j1Module()
{
	name.create("player");
}

j1Player::~j1Player()
{
}

bool j1Player::Awake()
{
	
	return true;
}

bool j1Player::Start()
{
	position.x = 100;
	position.y = 100;
	player_rect.h = 32;
	player_rect.w = 20;

	speed.x = 2;
	speed.y = 2;
	
	buttonD = new MoveRight;
	buttonA = new MoveLeft;
	buttonW = new MoveForward;
	buttonS = new MoveBackWard;

	Actor = Player;

	return true;
}

bool j1Player::PreUpdate()
{
	return true;
}

bool j1Player::Update(float dt)
{

	Movement();

	return true;
}

bool j1Player::Movement()
{
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
	{
		posaux = Actor->pos;
		App->task->AddTask(buttonA);
	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
	{
		posaux = Actor->pos;
		App->task->AddTask(buttonD);

	}
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
	{
		posaux = Actor->pos;
		App->task->AddTask(buttonW);
	}
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
	{
		posaux = Actor->pos;
		App->task->AddTask(buttonS);
	}

	if (App->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	{
		Task* auxtask = buttonA;
		buttonA = buttonD;
		buttonD = auxtask;
		auxtask = buttonS;
		buttonS = buttonW;
		buttonW = auxtask;
	}

	if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	{
		if (App->task->aux_task == nullptr)
		{
			if (Actor == Player)
			{
				Actor = Enemy;
			}
			else
				Actor = Player;
		}
	}
	return true;
}

bool j1Player::CleanUp()
{
	delete buttonD;
	delete buttonA;
	delete buttonW;
	delete buttonS;
	return true;
}
