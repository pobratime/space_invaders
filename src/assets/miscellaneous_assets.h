#ifndef MISCELLANEOUS_ASSETS_H
#define MISCELLANEOUS_ASSETS_H

#include "SDL3/SDL.h"

typedef struct{
  SDL_FRect em_1;
  SDL_FRect em_2;
  SDL_FRect em_3;
  SDL_FRect em_4;
}Emission_ship_1;

typedef struct{
  SDL_Texture *bmp_file;
  Emission_ship_1 emission_ship_1;
}Misc_assets;

void load_misc_assets(SDL_Renderer *renderer, Misc_assets *misc);

void load_spaceship_1_emission(Misc_assets *misc);
void load_spaceship_2_emission(Misc_assets *misc);
void load_spaceship_3_emission(Misc_assets *misc);
void load_spaceship_4_emission(Misc_assets *misc);

#endif
