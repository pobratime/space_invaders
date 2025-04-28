#ifndef ENEMY_H
#define ENEMY_H

#include <SDL3/SDL.h>

typedef struct{
  SDL_FRect idle_rect;
  SDL_FRect shooting_rect;
  SDL_FRect current_rect;
}EStripes;

typedef struct{
  float x, y;
  float velocity;
  float max_speed;
  float acceleration;
  float deacceleration;
  int direction;
}EMovemment;

typedef struct{
  float x, y;
  float velocity_y;
  int active;
  int type;
  SDL_FRect bullet_rect;
}EBullet;

typedef struct{
  float health_points;
}EData;

typedef struct{
  EStripes stripes;
  EBullet bullet;
  EMovemment movement;
  EData data;
}Enemy;

void init_enemies(void);
Enemy init_enemy_1(void);

#endif
