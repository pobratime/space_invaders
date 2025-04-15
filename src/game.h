#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "player.h"
#include "level.h"

typedef struct{
  SDL_Window *window;
  SDL_Renderer *renderer;
  Player player;
  Level current_level;
}Game;

void start_game(void);
void game_loop(Game *game);
void shut_down_game(Game *game);

#endif
