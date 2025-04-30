#ifndef SPACESHIP_ASSETS_H
#define SPACESHIP_ASSETS_H

#include "SDL3/SDL.h"

typedef struct{
  SDL_FRect idle;
  SDL_FRect steering_left;
  SDL_FRect steering_right;
}Spaceship_1_assets;

typedef struct{
  SDL_Texture *bmp_file;
  Spaceship_1_assets spaceship_1;
}Spaceship_assets;

void load_spaceship_assets(SDL_Renderer *renderer, Spaceship_assets *spaceship);
void load_spaceship_1_assets(Spaceship_assets *spaceship);

#endif
