#ifndef RENDER_OPTIONS_H
#define RENDER_OPTIONS_H

#include "SDL3/SDL.h"
#include "game/game.h"

void render_options(Game *game);
void render_title_options(Game *game);
void render_resolution_settings(Game *game);
void render_sound_settings(Game *game);
void render_return_button(Game *game);

#endif
