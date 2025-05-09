#ifndef GAME_UPDATE_H
#define GAME_UPDATE_H

#include "game/game.h"

void update_game(Game *game, float delta_time, bool key_states[]);
void update_background(Game *game, float delta_time);

void handle_welcome_state(Game *game);
void handle_options_state(Game *game);
void handle_game_over_state(Game *game);
void handle_playing_state(Game *game, float delta_time, bool key_states[]);

#endif
