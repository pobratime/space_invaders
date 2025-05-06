#ifndef PROJECTILES_ASSETS_H
#define PROJECTILES_ASSETS_H

#include "SDL3/SDL.h"

/**
 * Structure for all projectile types in the game
 */
typedef struct {
  SDL_Texture *bmp_file;   /* Projectiles texture atlas */
  SDL_FRect bullet_1;      /* Player's primary bullet */
  SDL_FRect bullet_2;      /* Small enemy bullet */
  SDL_FRect bullet_3;      /* Medium enemy bullet */
} Projectile_assets;

/* Function declarations */
void load_projectile_assets(SDL_Renderer *renderer, Projectile_assets *projectile);
void load_bullet_1_assets(Projectile_assets *projectile);
void load_bullet_2_assets(Projectile_assets *projectile);
void load_bullet_3_assets(Projectile_assets *projectile);

#endif /* PROJECTILES_ASSETS_H */
