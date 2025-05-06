#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

typedef struct{
  float x, y;
  int active;
  int type;
  SDL_FRect bullet_rect;
}Bullet;

typedef struct{
  float x, y;
  float velocity_x;
  float max_speed;
  float acceleration;
  float deacceleration;
  float turn_factor;
}Movement;

typedef struct{

  float health_points;
  float score;

  SDL_FRect current_player_rect;
  SDL_FRect current_emission_rect;
  int current_emission_int;
}Data;

typedef struct{
  Bullet bullet;
  Movement movement;
  Data data;
}Player;

void init_player(Player *player);


void update_player_bullet(Player *player, float delta);
void player_move_left(Player *player);
void player_move_right(Player *player);
void player_idle(Player *player);
void player_shoot(Player *player);


#endif
