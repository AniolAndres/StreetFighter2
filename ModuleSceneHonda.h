#ifndef __MODULESCENEHONDA_H__
#define __MODULESCENEHONDA_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"


struct SDL_Texture;

class ModuleSceneHonda : public Module
{
public:
	ModuleSceneHonda(bool start_enabled = false);
	~ModuleSceneHonda();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture * graphics = nullptr;
	SDL_Rect ground;
	SDL_Rect lowerBathtub;
	SDL_Rect upperBathtub;
	SDL_Rect background;
	SDL_Rect leftWall;
	SDL_Rect ceiling;
	SDL_Rect bucket;
	Animation waterTub;
	Animation mountain;
};

#endif // __MODULESCENEHONDA_H__