#ifndef UPDATE_SETTINGS_STATE_H
#define UPDATE_SETTINGS_STATE_H

#include "game/game.h"

void handle_settings_state(Game *game, float delta_time, SDL_Scancode pressed_key);
void update_settings_buttons(Game *game, float detla_time);

#endif
