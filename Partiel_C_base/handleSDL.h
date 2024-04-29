#pragma once

#include "structs.h"

void ErrorHandling(char* message, SDL sdl);
SDL StartSDL();
void CloseSDL(GameArgs gameArgs);
void WindowClear(SDL_Renderer* renderer);