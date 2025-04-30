#ifndef UPDATE_PLAYING_STATE
#define UPDATE_PLAYING_STATE

#include "game/game.h"

void handle_playing_state(Game *game, float delta_time, SDL_Scancode pressed_key);

void update_player_movement(Game *game, float delta_time);
void move_player_left(Player *player);
void move_player_right(Player *player);
void move_player_idle(Player *player);
void update_player_emission(Game *game, float delta_time);

#endif
