#ifndef RENDERER_H
#define RENDERER_H

#include "game.h"
#include <SDL3/SDL.h>
#include "game.h"

void render_player_bullets(Game *game);
void render_game(Game *game);
void render_background(Game *game);
void render_player(Game *game);
void render_enemies(Game *game);
void render_ui_elements(Game *game);
void render_collisions_bullet_and_enemy(Game *game);

#endif
