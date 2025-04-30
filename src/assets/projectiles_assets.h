#ifndef PROJECTILES_ASSETS_H
#define PROJECTILES_ASSETS_H

#include "SDL3/SDL.h"

typedef struct{
  SDL_Texture *bmp_file;
  SDL_FRect bullet_1;
  SDL_FRect bullet_2;
  SDL_FRect bullet_3;
}Projectile_assets;

void load_projectile_assets(SDL_Renderer *renderer, Projectile_assets *projectile);
void load_bullet_1_assets(Projectile_assets *projectile);
void load_bullet_2_assets(Projectile_assets *projectile);
void load_bullet_3_assets(Projectile_assets *projcetile);

#endif
