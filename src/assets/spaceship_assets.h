#ifndef SPACESHIP_ASSETS_H
#define SPACESHIP_ASSETS_H

#include "SDL3/SDL.h"

/**
 * Structure for spaceship 1 animation states
 */
typedef struct {
  SDL_FRect idle;          /* Default spaceship position */
  SDL_FRect steering_left; /* Spaceship when turning left */
  SDL_FRect steering_right;/* Spaceship when turning right */
} Spaceship_1_assets;

/**
 * Main spaceship assets structure
 */
typedef struct {
  SDL_Texture *bmp_file;   /* Primary spaceship texture */
  SDL_Texture *bmp_file_2; /* Secondary spaceship texture */
  Spaceship_1_assets spaceship_1; /* Spaceship type 1 assets */
} Spaceship_assets;

/* Function declarations */
void load_spaceship_assets(SDL_Renderer *renderer, Spaceship_assets *spaceship);
void load_spaceship_1_assets(Spaceship_assets *spaceship);

#endif /* SPACESHIP_ASSETS_H */
