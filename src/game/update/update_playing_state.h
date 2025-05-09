#ifndef UPDATE_PLAYING_STATE
#define UPDATE_PLAYING_STATE

#include "game/game.h"

void handle_playing_state(Game *game, float delta_time, bool key_states[]);

void update_player_movement(Game *game, float delta_time);
void move_player_left(Player *player);
void move_player_right(Player *player);
void move_player_idle(Player *player);
void update_player_emission(Game *game, float delta_time);
void player_shoot(Game *game, float delta_time);
void shoot_bullet(Game *game, float delta_time);
void update_player_bullets(Game *game, float delta_time);

#endif
