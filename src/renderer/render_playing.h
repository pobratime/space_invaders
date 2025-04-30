#ifndef RENDER_PLAYING_H
#define RENDER_PLAYING_H

#include "SDL3/SDL.h"
#include "game/game.h"
#include "assets/assets.h"

void render_playing(Game *game);

void render_player(Game *game);
void render_player_bullets(Game *game);

void render_enemies(Game *game);
void render_enemy_bullets(Game *game);

void render_ui_elements(Game *game);
void render_scoreboard(Game *game);
void render_health_bar(Game *game);

#endif
