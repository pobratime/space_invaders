#include "background_assets.h"
#include <stdio.h>

void load_background_assets(SDL_Renderer *renderer, Background_assets *background) {
  /* Load the background bitmap */
  SDL_Surface *background_surface_1 = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/background_1.bmp");
  SDL_Surface *background_surface_2 = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/background_2.bmp");
  SDL_Surface *background_surface_3 = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/background_3.bmp");
  SDL_Surface *background_surface_4 = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/background_4.bmp");
  
  /* Check if surface loaded correctly */
  if (background_surface_1 == NULL ||
      background_surface_2 == NULL ||
      background_surface_3 == NULL ||
      background_surface_4 == NULL) {

    fprintf(stderr, "Error loading background BMP file: %s\n", SDL_GetError());
    return;
  }

  /* Create texture from surface */
  background->bmp_file_1 = SDL_CreateTextureFromSurface(renderer, background_surface_1);
  background->bmp_file_2 = SDL_CreateTextureFromSurface(renderer, background_surface_2);
  background->bmp_file_3 = SDL_CreateTextureFromSurface(renderer, background_surface_3);
  background->bmp_file_4 = SDL_CreateTextureFromSurface(renderer, background_surface_4);
  
  /* Check if texture created correctly */
  if (background->bmp_file_1 == NULL ||
      background->bmp_file_2 == NULL || 
      background->bmp_file_3 == NULL ||
      background->bmp_file_4 == NULL){
    fprintf(stderr, "Error creating background texture: %s\n", SDL_GetError());
    SDL_DestroySurface(background_surface_1);
    SDL_DestroySurface(background_surface_2);
    SDL_DestroySurface(background_surface_3);
    SDL_DestroySurface(background_surface_4);
    return;
  }

  /* Load all background layer assets */
  load_background_1_asset(background);
  load_background_2_asset(background);
  load_background_3_asset(background);
  load_background_4_asset(background);

  /* Configure texture properties */
  SDL_SetTextureScaleMode(background->bmp_file_1, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(background->bmp_file_1, SDL_BLENDMODE_BLEND);
  SDL_SetTextureAlphaMod(background->bmp_file_1, 128.0f);

  SDL_SetTextureScaleMode(background->bmp_file_2, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(background->bmp_file_2, SDL_BLENDMODE_BLEND);
  SDL_SetTextureAlphaMod(background->bmp_file_2, 64.0f);

  SDL_SetTextureScaleMode(background->bmp_file_3, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(background->bmp_file_3, SDL_BLENDMODE_BLEND);
  SDL_SetTextureAlphaMod(background->bmp_file_3, 16.0f);
  
  SDL_SetTextureScaleMode(background->bmp_file_4, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(background->bmp_file_4, SDL_BLENDMODE_BLEND);

  /* Clean up surface */
  SDL_DestroySurface(background_surface_1);
  SDL_DestroySurface(background_surface_2);
  SDL_DestroySurface(background_surface_3);
  SDL_DestroySurface(background_surface_4);
}

void load_background_1_asset(Background_assets *background) {
  /* Define background layer 1 rectangle */
  SDL_FRect rect = {0.0f, 0.0f, 255.0f, 223.0f};
  background->rect_1 = rect;
}

void load_background_2_asset(Background_assets *background) {
  /* Define background layer 2 rectangle */
  SDL_FRect rect = {0.0f, 0.0f, 255.0f, 223.0f};
  background->rect_2 = rect;
}

void load_background_3_asset(Background_assets *background) {
  /* Define background layer 3 rectangle */
  SDL_FRect rect = {0.0f, 0.0f, 255.0f, 223.0f};
  background->rect_3 = rect;
}

void load_background_4_asset(Background_assets *background) {
  /* Define background layer 4 rectangle */
  SDL_FRect rect = {0.0f, 0.0f, 255.0f, 223.0f};
  background->rect_4 = rect;
}
