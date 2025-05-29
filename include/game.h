#ifndef GAME_H
#define GAME_H

#include "main.h"

typedef struct Game
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool is_running;
} Game;

Game *create_game();
void destroy_game(Game *game);
void run_game(Game *game);

#endif