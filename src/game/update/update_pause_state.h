#ifndef UPDATE_PAUSE_STATE_H
#define UPDATE_PAUSE_STATE_H

#include "game/game.h"
#include "SDL3/SDL.h"

void handle_paused_state(Game *game, float delta_time, bool key_states[]);
void update_pause_button_states(Game *game);

#endif
