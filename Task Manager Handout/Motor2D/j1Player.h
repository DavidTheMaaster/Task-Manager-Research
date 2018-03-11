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

	//TODO 4 Delete this functions when the TODO 2 is done
	bool MoveForward();
	bool MoveBackward();
	bool MoveLeft();
	bool MoveRight();

public:
	iPoint posaux;
	iPoint speed;

	Entity* Player = nullptr;
	Entity* Enemy = nullptr;
	Entity* Actor = nullptr;
private:
	//TODO 4 Add new task for each button
};



#endif // !_J1PLAYER_H__

