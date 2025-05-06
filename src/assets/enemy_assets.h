#ifndef ENEMY_ASSETS_H
#define ENEMY_ASSETS_H

#include "SDL3/SDL.h"

/**
 * Structure for boss enemy assets
 */
typedef struct {
  SDL_FRect boss_1;  /* Main boss appearance */
} Boss_assets;

/**
 * Structure for first enemy type assets
 */
typedef struct {
  SDL_FRect rect;    /* Enemy type 1 appearance */
} Enemy_1_assets;

/**
 * Structure for second enemy type assets
 */
typedef struct {
  SDL_FRect rect;    /* Enemy type 2 appearance */
} Enemy_2_assets;

/**
 * Main enemy assets structure
 */
typedef struct {
  SDL_Texture *bmp_file;  /* Texture containing all enemy sprites */

  Enemy_1_assets enemy_1; /* Standard enemy type 1 */
  Enemy_2_assets enemy_2; /* Standard enemy type 2 */
  Boss_assets boss;       /* Boss enemy assets */
} Enemy_assets;

/* Function declarations */
void load_enemy_assets(SDL_Renderer *renderer, Enemy_assets *enemy);
void load_enemy_1_assets(Enemy_assets *enemy);
void load_enemy_2_assets(Enemy_assets *enemy);
void load_boss_1_assets(Enemy_assets *enemy);

#endif /* ENEMY_ASSETS_H */
