#include <SDL.h>
#include <stdio.h>

#include "handleSDL.h"
#include "structs.h"
#include "game_events.h"

void HandleInputs(GameArgs* args)
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0){
        switch (event.type) {
            case SDL_QUIT:
                QuitGame(*args);
        }
    }
}