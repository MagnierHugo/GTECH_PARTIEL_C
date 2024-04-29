#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "game_events.h"
#include "handleSDL.h"
#include "init.h"
#include "structs.h"
#include "player.h"
#include "apple.h"


static void Update(GameArgs* args)
{
	
}

static void Draw(GameArgs* args)
{
	SDL_Renderer* renderer = args->SDL.renderer;
	Player player = args->Entities.player;
	Apple* apples = args->Entities.apples;

	WindowClear(renderer);
	SDL_RenderDrawRect(renderer, GetPlayerRect(player));
	for (int i = 0; i < args->Entities.nbrApple; i++)
	{
		SDL_RenderDrawRect(renderer, GetAppleRect(apples[i]));
	}
}

static void GameLoop(GameArgs* args)
{
	while (args->State.GameIsRunning) {
		Tick(&args->State);
		Update(args);

		
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));

	SDL sdlStruct = StartSDL();
	Entities entities = InitEntities();
	GameState state = InitGameState(sdlStruct);
	GameArgs args = {
		sdlStruct, entities, state
	};

	GameLoop(&args);

	QuitGame(args);
}