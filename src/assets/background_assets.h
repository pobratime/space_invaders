#ifndef BACKGROUND_ASSETS_H
#define BACKGROUND_ASSETS_H

#include "SDL3/SDL.h"

typedef struct{
  SDL_Texture *bmp_file_1;
  SDL_Texture *bmp_file_2;
  SDL_Texture *bmp_file_3;
  SDL_Texture *bmp_file_4;

  SDL_FRect rect_1;
  SDL_FRect rect_2;
  SDL_FRect rect_3;
  SDL_FRect rect_4;
}Background_assets;

void load_background_assets(SDL_Renderer *renderer, Background_assets *background);
void load_background_1_asset(Background_assets *background);
void load_background_2_asset(Background_assets *background);
void load_background_3_asset(Background_assets *background);
void load_background_4_asset(Background_assets *background);

#endif
