#include <SDL.h>
#include <SDL_mixer.h>
#include <stdlib.h>

#include "constants.h"
#include "structs.h"


void ErrorHandling(char* message, SDL sdl)
{
    printf("%s\n", message);
    if (&sdl != &(SDL) { NULL, NULL, NULL }) {

        if (sdl.window != NULL) {

            if (sdl.renderer != NULL) {
                if (sdl.Font != NULL) {
                    TTF_CloseFont(sdl.Font);
                }
            }
            SDL_DestroyWindow(sdl.window);
        }
        SDL_Quit();
    }
    exit(EXIT_FAILURE);
}


static void InitSDL(SDL sdl)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        ErrorHandling("Erreur SDL Init failed", sdl);
    }

    if (TTF_Init() != 0) {
        ErrorHandling("Erreur SDL_ttf failed", sdl);
    }

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        ErrorHandling("Erreur initialisation de SDL Audio", sdl);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, NUMBER_OF_CHANNELS, 2048) < 0)
    {
        ErrorHandling("Erreur initialisation de SDL Mixer", sdl);
    }
    Mix_Volume(0, 7);

    if (TTF_Init() < 0) {
        ErrorHandling("Erreur initialisation de SDL TTF", sdl);
    }

    if (SDL_Init(SDL_INIT_JOYSTICK) < 0) {
        ErrorHandling("Erreur Joystick Init failed", sdl);
    }
}

SDL StartSDL()
{
    srand(time(NULL));
    SDL sdl;

    InitSDL(sdl);

    sdl.window = SDL_CreateWindow("Ship game", //creer une fenetre avec SDL
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );

    if (sdl.window == NULL) {
        ErrorHandling("Erreur creation fen�tre SDL", sdl);
    }

    sdl.renderer = SDL_CreateRenderer(//Creer rendu SDL
        sdl.window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (sdl.renderer == NULL) {
        ErrorHandling("Erreur creation rendu SDL", sdl);
    }

    sdl.Font = TTF_OpenFont("../Font/font.fon", 24);// Load font
    if (sdl.Font == NULL) {
        ErrorHandling("Erreur chargement de la police", sdl);
    }

    return sdl;
}

void CloseSDL(GameArgs gameArgs)
{
    TTF_CloseFont(gameArgs.SDL.Font);
    SDL_DestroyRenderer(gameArgs.SDL.renderer);
    SDL_DestroyWindow(gameArgs.SDL.window);

    SDL_Quit();
}

void WindowClear(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}