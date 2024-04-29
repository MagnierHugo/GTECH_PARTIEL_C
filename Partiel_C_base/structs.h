#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdbool.h>

typedef struct {
	SDL_Window* window;
	SDL_Renderer* renderer;
	TTF_Font* Font;
} SDL;

typedef struct {
	float x;
	float y;
	int width;
	int height;

	int dir_x;
	int dir_y;
	float speed;
} Player;

typedef struct {
	float x;
	float y;
	int width;
	int height;
} Apple;

typedef struct {
	Player player;
	Apple* apples;
	int nbrApple;
	int maxApple;
} Entities;

typedef struct {
	float DeltaTime;
	float CurrentTime;
	int Score;
	bool GameIsRunning;
} GameState;

typedef struct {
	SDL SDL;
	Entities Entities;
	GameState State;
} GameArgs;
