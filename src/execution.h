#ifndef EXECUTION_H
#define EXECUTION_H

#include "game/game.h"

void start_game(void);
void game_loop(Game *game);
void update_background(Game *game, float delta);
void shut_down_game(Game *game);

#endif
