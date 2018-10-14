#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"


struct SDL_Texture;

class ModuleSceneKen : public Module
{
public:
	ModuleSceneKen( bool start_enabled = true);
	~ModuleSceneKen();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture * graphics = nullptr;
	SDL_Rect ship;
	SDL_Rect ground;
	SDL_Rect background;
	Animation flag;
	Animation girl;
	int clock = 0;
	int shipMovementInc = 4;
	bool shipMovementUp=true;
};

#endif // __MODULESCENEKEN_H__