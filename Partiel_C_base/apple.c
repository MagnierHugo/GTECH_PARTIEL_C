#include "constants.h"
#include "structs.h"

void CreateApple(Entities* entities)
{
	if (entities->nbrApple < entities->maxApple) {
		entities->apples = realloc(entities->apples, entities->nbrApple * sizeof(Apple));
		entities->maxApple = entities->nbrApple;
	}

	Apple apple = {
		rand(0, SCREEN_WIDTH), rand(0, SCREEN_HEIGHT),
		20, 20
	};
	
	entities->apples[entities->nbrApple] = apple;
}

SDL_Rect* GetAppleRect(Apple apple)
{
	SDL_Rect rect = {
		apple.x, apple.y, apple.width, apple.height
	};

	return &rect;
}