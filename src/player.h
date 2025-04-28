#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

typedef struct{
  float x, y;
  float velocity_y;
  int active;
  int type;
  SDL_FRect bullet_rect;
}Bullet;

typedef struct{
  SDL_FRect current_rect;
  SDL_FRect idle_rect;
  SDL_FRect steering_left_rect;
  SDL_FRect steering_right_rect;
}Sprites;

typedef struct{
  float x, y;
  float velocity_x;
  float max_speed;
  float acceleration;
  float deacceleration;
}Movement;

typedef struct{
  float health_points;
  float score;
}Data;

typedef struct{
  Sprites sprites;
  Bullet bullet;
  Movement movement;
  Data data;
}Player;



void init_player(Player *player);


void update_player_bullet(Player *player, float delta);
void update_player_movement(Player *player, float delta);
void player_move_left(Player *player);
void player_move_right(Player *player);
void player_idle(Player *player);

void player_shoot(Player *player);


#endif
