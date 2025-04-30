#ifndef ENEMY_ASSETS_H
#define ENEMY_ASSETS_H

#include "SDL3/SDL.h"

typedef struct{
  SDL_FRect boss_1;
}Boss_assets;

typedef struct{
  SDL_FRect rect;
}Enemy_1_assets;

typedef struct{
  SDL_FRect rect;
}Enemy_2_assets;

typedef struct{
  SDL_Texture *bmp_file;

  Enemy_1_assets enemy_1;
  Enemy_2_assets enemy_2;
  Boss_assets boss;
}Enemy_assets;

void load_enemy_assets(SDL_Renderer *renderer, Enemy_assets *enemy);
void load_enemy_1_assets(Enemy_assets *enemy);
void load_enemy_2_assets(Enemy_assets *enemy);
void load_boss_1_assets(Enemy_assets *enemy);

#endif
