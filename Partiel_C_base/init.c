#include <stdbool.h>
#include <stdlib.h>

#include "apple.h"
#include "constants.h"
#include "structs.h"


Entities InitEntities()
{
	Player player = {
		SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		30, 30, 0, 0, 200
	};

	Apple* apples = malloc(sizeof(Apple));

	Apple apple = {
		rand(0, SCREEN_WIDTH), rand(0, SCREEN_HEIGHT),
		20, 20
	};

	int maxApple = 1;
	int nbrApple = 1;

	Entities entities = {
		player, apples, nbrApple, maxApple
	};

	return entities;
}

GameState InitGameState(SDL sdl)
{
	GameState gState;
	gState.DeltaTime = 0;
	gState.CurrentTime = SDL_GetTicks();
	gState.GameIsRunning = true;
	gState.Score = 0;

	return gState;
}