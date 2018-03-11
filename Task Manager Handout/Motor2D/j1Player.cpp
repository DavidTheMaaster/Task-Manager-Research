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
	speed.x = 2;
	speed.y = 2;
	
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


bool j1Player::CleanUp()
{
	//TODO 4 Remember to delete the new Tasks
	return true;
}

bool j1Player::Movement()
{
	//TODO 4 Add the task to the queque 

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		posaux = Actor->pos;
		MoveLeft();
	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		posaux = Actor->pos;
		MoveRight();


	}
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		posaux = Actor->pos;
		MoveForward();

	}
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		posaux = Actor->pos;
		MoveBackward();
	}

	if (App->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	{
		//TODO 5 Exchange task so when you press A it goes to the right an so  
	}

	if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	{
		//TODO 6 Change the actor of the action
	}


	return true;
}


bool j1Player::MoveLeft()
{
	if (Player->pos.x == posaux.x - 32)
	{
		posaux.x = Player->pos.x;
	}
	else
	{
		Player->pos.x -= speed.x;
	}
		return true;
}

bool j1Player::MoveRight()
{
	if (Player->pos.x == posaux.x + 32)
	{
		posaux.x = Player->pos.x;
	}
	else
	{
		Player->pos.x += speed.x;
	}
	return true;
}

bool j1Player::MoveForward()
{
	if (Player->pos.y == posaux.y - 32)
	{
		posaux.y = Player->pos.y;

	}
	else
	{
		Player->pos.y -= speed.y;
	}
	return false;
}

bool j1Player::MoveBackward()
{
	if (Player->pos.y == posaux.y + 32)
	{
		posaux.y = Player->pos.y;

	}
	else
	{
		Player->pos.y += speed.y;
	}
	return false;
}
