#include <stdio.h>
#include <stdlib.h>

#include "structs.h"


int QuitGame(GameArgs gameArgs)
{
	GameState state = gameArgs.State;
	printf("Thanks for playing");
	CloseSDL(gameArgs);
	exit(EXIT_SUCCESS);
	return 0;
}

void Tick(GameState* state)
{
	state->DeltaTime = (SDL_GetTicks() - state->CurrentTime) / 1000;
	state->CurrentTime = SDL_GetTicks();
}