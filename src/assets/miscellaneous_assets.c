#include "miscellaneous_assets.h"
#include <stdio.h>

void load_misc_assets(SDL_Renderer *renderer, Misc_assets *misc) {
  /* Load bitmap surfaces */
  SDL_Surface *misc_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/miscellaneous.bmp");
  SDL_Surface *misc_surface_2 = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/ui_2.bmp");

  /* Check if surfaces loaded correctly */
  if (misc_surface == NULL) {
    fprintf(stderr, "Error loading miscellaneous BMP file: %s\n", SDL_GetError());
    return;
  }
  
  if (misc_surface_2 == NULL) {
    fprintf(stderr, "Error loading UI 2 BMP file: %s\n", SDL_GetError());
    SDL_DestroySurface(misc_surface);
    return;
  }

  /* Create textures from surfaces */
  misc->bmp_file = SDL_CreateTextureFromSurface(renderer, misc_surface);
  misc->bmp_file_2 = SDL_CreateTextureFromSurface(renderer, misc_surface_2);

  /* Check if textures created correctly */
  if (misc->bmp_file == NULL) {
    fprintf(stderr, "Error creating miscellaneous texture: %s\n", SDL_GetError());
    SDL_DestroySurface(misc_surface);
    SDL_DestroySurface(misc_surface_2);
    return;
  }
  
  if (misc->bmp_file_2 == NULL) {
    fprintf(stderr, "Error creating UI 2 texture: %s\n", SDL_GetError());
    SDL_DestroyTexture(misc->bmp_file);
    SDL_DestroySurface(misc_surface);
    SDL_DestroySurface(misc_surface_2);
    return;
  }

  /* Configure texture properties */
  SDL_SetTextureScaleMode(misc->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(misc->bmp_file, SDL_BLENDMODE_BLEND);

  SDL_SetTextureScaleMode(misc->bmp_file_2, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(misc->bmp_file_2, SDL_BLENDMODE_BLEND);

  /* Load engine emission effects */
  load_spaceship_1_emission(misc);
  load_spaceship_2_emission(misc);
  load_spaceship_3_emission(misc);
  /* Clean up surfaces */
  SDL_DestroySurface(misc_surface);
  SDL_DestroySurface(misc_surface_2);
}

void load_spaceship_1_emission(Misc_assets *misc) {
  SDL_FRect rect = {81.0f, 104.0f, 6.0f, 4.0f};
  misc->emission_ship_1.em_1 = rect;
}

void load_spaceship_2_emission(Misc_assets *misc) {
  SDL_FRect rect = {90.0f, 104.0f, 6.0f, 6.0f};
  misc->emission_ship_1.em_2 = rect;
}

void load_spaceship_3_emission(Misc_assets *misc) {
  SDL_FRect rect = {98.0f, 104.0f, 6.0f, 8.0f};
  misc->emission_ship_1.em_3 = rect;
}


