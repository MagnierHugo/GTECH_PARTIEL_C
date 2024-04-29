#include <SDL.h>

#include "structs.h"

SDL_Rect* GetPlayerRect(Player player)
{
	SDL_Rect rect = {
		player.x, player.y, player.width, player.height
	};

	return &rect;
}