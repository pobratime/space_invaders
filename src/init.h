#ifndef INIT_H
#define INIT_H

#include <SDL3/SDL.h>
#include "game/game.h"

void init_game_window_and_renderer(Game *game);
void init_window(Game *game);
void init_renderer(Game *game);
void init_audio(Game *game);

#endif
