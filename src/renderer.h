#ifndef RENDERER_H
#define RENDERER_H

#include "game.h"
#include "enemy.h"
#include <SDL3/SDL.h>
#include "game.h"

void render_game(Game *game);
void render_background(Game *game);
void render_player(Game *game);
void render_enemies(Game *game);
void render_enemy(Game *game, Enemy *enemy);
// void render_bullets();

#endif
