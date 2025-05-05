#ifndef RENDER_PAUSE_H
#define RENDER_PAUSE_H

#include "SDL3/SDL.h"
#include "game/game.h"
#include "SDL3_ttf/SDL_ttf.h"

void render_pause(Game *game);
void render_pause_menu(Game *game);
void render_pause_header(Game *game);
void update_pause_button_states(Game *game);

#endif
