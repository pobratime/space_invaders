#include "background_assets.h"

void load_background_assets(SDL_Renderer *renderer, Background_assets *background){

  // TMP
  SDL_Surface *background_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/background_stock.bmp");
  
  // SDL_Surface *background_surface = SDL_LoadBMP("src/assets/background.bmp");
  if(background_surface == NULL)
    fprintf(stderr, "Error while loading a background BMP file: %s\n", SDL_GetError());

  background->bmp_file = SDL_CreateTextureFromSurface(renderer, background_surface);
  if(background->bmp_file == NULL)
    fprintf(stderr, "Error while creating a projectile texture from a BMP file: %s\n", SDL_GetError());

  load_background_1_asset(background);
  // load_background_2_asset(background);
  // load_background_3_asset(background);
  // load_background_4_asset(background);

  SDL_SetTextureScaleMode(background->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(background->bmp_file, SDL_BLENDMODE_BLEND);

  SDL_DestroySurface(background_surface);
}

void load_background_1_asset(Background_assets *background){
  SDL_FRect rect = {0.0f, 0.0f, 255.0f, 127.0f};
  background->rect_1 = rect;
}

// void load_background_2_asset(Background_assets *background){
//   SDL_FRect rect = {0.0f, 129.0f, 255.0f, 127.0f};
//   background->rect_2 = rect;
// }

// void load_background_3_asset(Background_assets *background){
//   SDL_FRect rect = {0.0f, 259.0f, 255.0f, 127.0f};
//   background->rect_3 = rect;
// }

// void load_background_4_asset(Background_assets *background){
//   SDL_FRect rect = {257.0f, 255.0f, 255.0f, 127.0f};
//   background->rect_4 = rect;
// }
