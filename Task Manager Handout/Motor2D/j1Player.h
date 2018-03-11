#ifndef _J1PLAYER_H__
#define _J1PLAYER_H__

#include "j1Module.h"
#include "p2Point.h"
#include "SDL/include/SDL.h"

#include <queue>

class Task;
class Entity;

class j1Player : public j1Module
{
public:
	j1Player();
	virtual ~j1Player();

	bool Awake();

	bool Start();

	bool PreUpdate();

	bool Update(float dt);

	bool Movement();

	bool CleanUp();

	bool MoveForward();
	bool MoveBackward();
	bool MoveLeft();
	bool MoveRight();

public:
	iPoint position;
	iPoint posaux;
	SDL_Rect player_rect;
	iPoint speed;

	Entity* Player = nullptr;
	Entity* Enemy = nullptr;
	Entity* Actor = nullptr;
private:
};



#endif // !_J1PLAYER_H__
