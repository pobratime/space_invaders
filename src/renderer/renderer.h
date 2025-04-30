#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>

#include "render_game_over.h"
#include "render_options.h"
#include "render_pause.h"
#include "render_playing.h"
#include "render_welcome.h"
#include "render_menu.h"

#include "game/game.h"

void render_game(Game *game);
void render_background(Game *game);

#endif
