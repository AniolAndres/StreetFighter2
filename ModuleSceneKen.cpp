#include "Globals.h"
#include "Application.h"
#include "ModuleSceneKen.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneKen::ModuleSceneKen(bool start_enabled) : Module(start_enabled)
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// TODO 2 : setup the foreground (red ship) with

	ship.x = 0;
	ship.y = 0;
	ship.w = 550;
	ship.h = 250;

	// coordinates x,y,w,h from ken_stage.png

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// flag animation
	flag.frames.push_back({848, 208, 40, 40});
	flag.frames.push_back({848, 256, 40, 40});
	flag.frames.push_back({848, 304, 40, 40});
	flag.speed = 0.08f;

	// TODO 4: Setup Girl Animation from coordinates from ken_stage.png

	girl.frames.push_back({ 625, 18, 30, 55 });
	girl.frames.push_back({ 625, 82, 30, 55 });
	girl.frames.push_back({ 625, 146, 30, 55 });
	girl.speed = 0.08f;

}

ModuleSceneKen::~ModuleSceneKen()
{}

// Load assets
bool ModuleSceneKen::Start()
{
	LOG("Loading ken scene");
	
	graphics = App->textures->Load("ken_stage.png");

	// TODO 7: Enable the player module

	App->player->Enable();

	// TODO 0: trigger background music

	App->audio->PlayMusic("ken.ogg");

	return true;
}

// UnLoad assets
bool ModuleSceneKen::CleanUp()
{
	LOG("Unloading ken scene");

	App->textures->Unload(graphics);
	App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneKen::Update()
{
	// TODO 5: make sure the ship goes up and down
	++clock;
	if (clock % 50 == 0)
	{
		if (shipMovementUp)
			++shipMovementInc;
		else
			--shipMovementInc;

		if (shipMovementInc == 5)
			shipMovementUp = false;
		else if (shipMovementInc == -1)
			shipMovementUp = true;
	}

	// Draw everything --------------------------------------	

	// TODO 1: Tweak the movement speed of the sea&sky + flag to your taste
	App->renderer->Blit(graphics, 0, 0, &background, 1.5f); // sea and sky
	
	App->renderer->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()),1.5f); // flag animation

	// TODO 3: Draw the ship. Be sure to tweak the speed.

	App->renderer->Blit(graphics, -50, -24 + shipMovementInc, &ship, 1.3f);

	// TODO 6: Draw the girl. Make sure it follows the ship movement!

	App->renderer->Blit(graphics, 150, 106 + shipMovementInc, &(girl.GetCurrentFrame()), 1.3f);
	
	App->renderer->Blit(graphics, 0, 170, &ground);

	// TODO 10: Build an entire new scene "honda", you can find its
	// and music in the Game/ folder

	// TODO 11: Make that pressing space triggers a switch to honda logic module
	// using FadeToBlack module

	return UPDATE_CONTINUE;
}