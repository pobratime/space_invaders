#include "spaceship_assets.h"
#include <stdio.h>

void load_spaceship_assets(SDL_Renderer *renderer, Spaceship_assets *spaceship) {
  /* Load bitmap surfaces */
  SDL_Surface *spaceship_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/spaceships.bmp");
  SDL_Surface *misc_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/miscellaneous_2.bmp");

  /* Check if surfaces loaded correctly */
  if (spaceship_surface == NULL) {
    fprintf(stderr, "Error loading spaceship BMP file: %s\n", SDL_GetError());
    return;
  }
  
  if (misc_surface == NULL) {
    fprintf(stderr, "Error loading misc BMP file: %s\n", SDL_GetError());
    SDL_DestroySurface(spaceship_surface);
    return;
  }

  /* Create textures from surfaces */
  spaceship->bmp_file = SDL_CreateTextureFromSurface(renderer, spaceship_surface);
  spaceship->bmp_file_2 = SDL_CreateTextureFromSurface(renderer, misc_surface);

  /* Check if textures created correctly */
  if (spaceship->bmp_file == NULL) {
    fprintf(stderr, "Error creating spaceship texture: %s\n", SDL_GetError());
    SDL_DestroySurface(spaceship_surface);
    SDL_DestroySurface(misc_surface);
    return;
  }
  
  if (spaceship->bmp_file_2 == NULL) {
    fprintf(stderr, "Error creating misc texture: %s\n", SDL_GetError());
    SDL_DestroyTexture(spaceship->bmp_file);
    SDL_DestroySurface(spaceship_surface);
    SDL_DestroySurface(misc_surface);
    return;
  }

  /* Configure texture properties */
  SDL_SetTextureScaleMode(spaceship->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(spaceship->bmp_file, SDL_BLENDMODE_BLEND);

  SDL_SetTextureScaleMode(spaceship->bmp_file_2, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(spaceship->bmp_file_2, SDL_BLENDMODE_BLEND);

  /* Load specific spaceship assets */
  load_spaceship_1_assets(spaceship);

  /* Clean up surfaces */
  SDL_DestroySurface(spaceship_surface);
  SDL_DestroySurface(misc_surface);
}

void load_spaceship_1_assets(Spaceship_assets *spaceship) {
  /* Define spaceship states */
  SDL_FRect idle = {18.0f, 88.0f, 12.0f, 14.0f};
  SDL_FRect steering_left = {52.0f, 88.0f, 7.0f, 14.0f};
  SDL_FRect steering_right = {68.0f, 88.0f, 7.0f, 14.0f};

  /* Assign to structure */
  spaceship->spaceship_1.idle = idle;
  spaceship->spaceship_1.steering_left = steering_left;
  spaceship->spaceship_1.steering_right = steering_right;
}

