#ifndef INIT_H
#define INIT_H

#include <SDL3/SDL.h>
#include "game/game.h"

int init_game_window_and_renderer(Game *game);
int init_window(Game *game);
int init_renderer(Game *game);

#endif
