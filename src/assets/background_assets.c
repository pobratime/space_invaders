#include "background_assets.h"
#include <stdio.h>

void load_background_assets(SDL_Renderer *renderer, Background_assets *background) {
  /* Load the background bitmap */
  SDL_Surface *background_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/background_stock.bmp");
  
  /* Check if surface loaded correctly */
  if (background_surface == NULL) {
    fprintf(stderr, "Error loading background BMP file: %s\n", SDL_GetError());
    return;
  }

  /* Create texture from surface */
  background->bmp_file = SDL_CreateTextureFromSurface(renderer, background_surface);
  
  /* Check if texture created correctly */
  if (background->bmp_file == NULL) {
    fprintf(stderr, "Error creating background texture: %s\n", SDL_GetError());
    SDL_DestroySurface(background_surface);
    return;
  }

  /* Load all background layer assets */
  load_background_1_asset(background);
  load_background_2_asset(background);
  load_background_3_asset(background);
  load_background_4_asset(background);

  /* Configure texture properties */
  SDL_SetTextureScaleMode(background->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(background->bmp_file, SDL_BLENDMODE_BLEND);

  /* Clean up surface */
  SDL_DestroySurface(background_surface);
}

void load_background_1_asset(Background_assets *background) {
  /* Define background layer 1 rectangle */
  SDL_FRect rect = {0.0f, 0.0f, 255.0f, 127.0f};
  background->rect_1 = rect;
}

void load_background_2_asset(Background_assets *background) {
  /* Define background layer 2 rectangle */
  SDL_FRect rect = {0.0f, 129.0f, 255.0f, 127.0f};
  background->rect_2 = rect;
}

void load_background_3_asset(Background_assets *background) {
  /* Define background layer 3 rectangle */
  SDL_FRect rect = {0.0f, 259.0f, 255.0f, 127.0f};
  background->rect_3 = rect;
}

void load_background_4_asset(Background_assets *background) {
  /* Define background layer 4 rectangle */
  SDL_FRect rect = {257.0f, 255.0f, 255.0f, 127.0f};
  background->rect_4 = rect;
}
