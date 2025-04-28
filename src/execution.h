#ifndef EXECUTION_H
#define EXECUTION_H

#include "game.h"

void start_game(void);
void game_loop(Game *game);
void update_background(float delta);
void shut_down_game(Game *game);

#endif
