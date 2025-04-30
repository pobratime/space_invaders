#include "miscellaneous_assets.h"

void load_misc_assets(SDL_Renderer *renderer, Misc_assets *misc){

  // TMP
  SDL_Surface *misc_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/miscellaneous.bmp");

  // SDL_Surface *projectile_surface = SDL_LoadBMP("src/assets/projectiles.bmp");
  if(misc_surface == NULL)
    fprintf(stderr, "Error while loading a misc BMP file: %s\n", SDL_GetError());

  misc->bmp_file = SDL_CreateTextureFromSurface(renderer, misc_surface);
  if(misc->bmp_file == NULL)
    fprintf(stderr, "Error while creating a misc texture from a BMP file: %s\n", SDL_GetError());

  SDL_SetTextureScaleMode(misc->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(misc->bmp_file, SDL_BLENDMODE_BLEND); 

  load_spaceship_1_emission(misc);
  load_spaceship_2_emission(misc);
  load_spaceship_3_emission(misc);
  load_spaceship_4_emission(misc);

  SDL_DestroySurface(misc_surface);
}

void load_spaceship_1_emission(Misc_assets *misc){
  SDL_FRect rect = {
    44.f, 1.0f, 1.0f, 3.0f
  };
  misc->emission_ship_1.em_1 = rect;
}

void load_spaceship_2_emission(Misc_assets *misc){
  SDL_FRect rect = {
    52.0f, 1.0f, 1.0f, 2.0f
  };
  misc->emission_ship_1.em_2 = rect;
}

void load_spaceship_3_emission(Misc_assets *misc){
  SDL_FRect rect = {
    60.0f, 1.0f, 1.0f, 3.0f
  };
  misc->emission_ship_1.em_3 = rect;
}

void load_spaceship_4_emission(Misc_assets *misc){
  SDL_FRect rect = {
    68.0f, 1.0f, 1.0f, 3.0f
  };
  misc->emission_ship_1.em_4 = rect;
}
