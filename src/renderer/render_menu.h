#ifndef RENDER_MENU_H
#define RENDER_MENU_H

#include "SDL3/SDL.h"
#include "SDL3_ttf/SDL_ttf.h"

#include "game/game.h"

void render_menu(Game *game);

void render_play_button(Game *game);
void render_settins_button(Game *game);
void render_exit_button(Game *game);
void render_title(Game *game);
void render_square(Game *game);
void render_feedback_button(Game *game);

#endif
