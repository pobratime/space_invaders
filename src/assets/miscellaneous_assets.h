#ifndef MISCELLANEOUS_ASSETS_H
#define MISCELLANEOUS_ASSETS_H

#include "SDL3/SDL.h"

/**
 * Structure for spaceship engine emissions
 */
typedef struct {
  SDL_FRect em_1;  /* Small engine emission */
  SDL_FRect em_2;  /* Medium engine emission */
  SDL_FRect em_3;  /* Large engine emission */
} Emission_ship_1;

/**
 * Structure for all miscellaneous game assets
 */
typedef struct {
  SDL_Texture *bmp_file;    /* Primary miscellaneous texture */
  SDL_Texture *bmp_file_2;  /* Secondary miscellaneous texture */
  
  Emission_ship_1 emission_ship_1; /* Engine emission effects */

} Misc_assets;

/* Function declarations */
void load_misc_assets(SDL_Renderer *renderer, Misc_assets *misc);

void load_spaceship_1_emission(Misc_assets *misc);
void load_spaceship_2_emission(Misc_assets *misc);
void load_spaceship_3_emission(Misc_assets *misc);

#endif /* MISCELLANEOUS_ASSETS_H */
