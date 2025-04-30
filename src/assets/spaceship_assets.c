#include "spaceship_assets.h"

void load_spaceship_assets(SDL_Renderer *renderer,
                           Spaceship_assets *spaceship) {

  // TMP
  SDL_Surface *spaceship_surface =
      SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/"
                  "spaceships.bmp");

  // SDL_Surface *spaceship_surface = SDL_LoadBMP("src/assets/spaceships.bmp");
  if (spaceship_surface == NULL)
    fprintf(stderr, "Error while loading a spaceship BMP file: %s\n",
            SDL_GetError());

  spaceship->bmp_file =
      SDL_CreateTextureFromSurface(renderer, spaceship_surface);
  if (spaceship->bmp_file == NULL)
    fprintf(stderr,
            "Error while creating a spaceship texture from a BMP file: %s\n",
            SDL_GetError());

  SDL_SetTextureScaleMode(spaceship->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(spaceship->bmp_file, SDL_BLENDMODE_BLEND);

  load_spaceship_1_assets(spaceship);

  SDL_DestroySurface(spaceship_surface);
}

void load_spaceship_1_assets(Spaceship_assets *spaceship) {
  SDL_FRect idle = {8.0f, 32.0f, 8.0f, 8.0f};
  SDL_FRect steering_left = {1.0f, 32.0f, 6.0f, 8.0f};
  SDL_FRect steering_right = {17.0f, 32.0f, 6.0f, 8.0f};

  spaceship->spaceship_1.idle = idle;
  spaceship->spaceship_1.steering_left = steering_left;
  spaceship->spaceship_1.steering_right = steering_right;
}

