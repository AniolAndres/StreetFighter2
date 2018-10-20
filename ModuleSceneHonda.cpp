#include "Globals.h"
#include "Application.h"
#include "ModuleSceneHonda.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneHonda::ModuleSceneHonda(bool start_enabled) : Module(start_enabled)
{
	// ground

	ground.x = 4;
	ground.y = 373;
	ground.w = 880;
	ground.h = 72;

	//lower lowerBathtub

	lowerBathtub.x = 308;
	lowerBathtub.y = 333;
	lowerBathtub.w = 348;
	lowerBathtub.h = 39;

	//upper bathtub

	upperBathtub.x = 308;
	upperBathtub.y = 307;
	upperBathtub.w = 348;
	upperBathtub.h = 27;

	//Background

	background.x = 114;
	background.y = 170;
	background.w = 682;
	background.h = 137;

	//left wall

	
	leftWall.x = 116;
	leftWall.y = 117;
	leftWall.w = 108;
	leftWall.h = 218;

	//ceiling


	ceiling.x = 87;
	ceiling.y = 2;
	ceiling.w = 789;
	ceiling.h = 59;

	//bucket

	bucket.x = 224;
	bucket.y = 312;
	bucket.w = 48;
	bucket.h = 40;

	// Water from the bath

	waterTub.frames.push_back({ 4, 445, 290, 19 });
	waterTub.frames.push_back({ 292, 445, 290, 19 });
	waterTub.frames.push_back({ 584, 445, 290, 19 });
	waterTub.speed = 0.02f;


	// mountain+sun from background

	mountain.frames.push_back({ 220, 61, 231, 110 });
	mountain.frames.push_back({ 452, 61, 231, 110 });
	mountain.speed = 0.025f;

}

ModuleSceneHonda::~ModuleSceneHonda()
{}

// Load assets
bool ModuleSceneHonda::Start()
{
	LOG("Loading honda scene");

	graphics = App->textures->Load("honda_stage.png");



	App->player->Enable();



	return true;
}

// UnLoad assets
bool ModuleSceneHonda::CleanUp()
{
	LOG("Unloading honda scene");

	App->textures->Unload(graphics);
	App->player->Disable();

	return true;
}

update_status ModuleSceneHonda::Update()
{
	//Background

	App->renderer->Blit(graphics, -20, 29, &background);

	//Ground

	App->renderer->Blit(graphics, -110, 160, &ground);

	//animation from the mountain+sun

	App->renderer->Blit(graphics, 174, 40, &(mountain.GetCurrentFrame()));

	//leftWall

	App->renderer->Blit(graphics, -20, -24, &leftWall);

	//ceiling

	App->renderer->Blit(graphics, -70, -19, &ceiling);

	//Bucket

	App->renderer->Blit(graphics, 70, 150, &bucket);

	//lowerBathtub

	App->renderer->Blit(graphics, 140, 150, &lowerBathtub);

	//upperBathtub

	App->renderer->Blit(graphics, 140, 132, &upperBathtub);

	//water from the tub

	App->renderer->Blit(graphics, 165, 145, &(waterTub.GetCurrentFrame()));



	return UPDATE_CONTINUE;
}
