#ifndef UPDATE_MENU_STATE_H
#define UPDATE_MENU_STATE_H

#include "game/game.h"
#include "SDL3/SDL.h"

void handle_menu_state(Game *game, float delta_time, SDL_Scancode pressed_key);
void outlay_selected_button(Game *game);

#endif
