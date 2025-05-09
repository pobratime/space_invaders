#ifndef UPDATE_AUDIO_H
#define UPDATE_AUDIO_H

#include "game/game.h"
#include "SDL3/SDL.h"

void handle_audio(Game *game, float delta_time);
void play_bullet_sound(Game *game, float delta_time);
void play_button_selection_sound(Game *game, float delta_time);
void play_button_clicked_sound(Game *game, float delta_time);

#endif
