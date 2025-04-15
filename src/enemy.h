#ifndef ENEMY_H
#define ENEMY_H

#include <SDL3/SDL.h>

typedef struct{
  SDL_FRect normal_rect;
  SDL_FRect shooting_rect;
  SDL_FRect current_rect;
  float x, y;
  float health_points;
}Enemy;

int init_enemy(Enemy *enemy, SDL_Renderer *renderer);

#endif
