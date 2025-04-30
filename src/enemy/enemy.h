#ifndef ENEMY_H
#define ENEMY_H

#include <SDL3/SDL.h>

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
  int active;
  int type;
  SDL_FRect bullet_rect;
}EBullet;

typedef struct{
  float health_points;
  float score;
}EData;

typedef struct{
  EBullet bullet;
  EMovemment movement;
  EData data;
}Enemy;

void init_enemies(void);
void enemy_shoot(Enemy *enemy);
Enemy init_enemy_1(void);

#endif
