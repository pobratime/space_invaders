#include "projectiles_assets.h"
#include <stdio.h>

void load_projectile_assets(SDL_Renderer *renderer, Projectile_assets *projectile) {
  /* Load bitmap surface */
  SDL_Surface *projectile_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/projectiles.bmp");

  /* Check if surface loaded correctly */
  if (projectile_surface == NULL) {
    fprintf(stderr, "Error loading projectile BMP file: %s\n", SDL_GetError());
    return;
  }

  /* Create texture from surface */
  projectile->bmp_file = SDL_CreateTextureFromSurface(renderer, projectile_surface);
  
  /* Check if texture created correctly */
  if (projectile->bmp_file == NULL) {
    fprintf(stderr, "Error creating projectile texture: %s\n", SDL_GetError());
    SDL_DestroySurface(projectile_surface);
    return;
  }

  /* Load all bullet assets */
  load_bullet_1_assets(projectile);
  load_bullet_2_assets(projectile);
  load_bullet_3_assets(projectile);

  /* Configure texture properties */
  SDL_SetTextureScaleMode(projectile->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(projectile->bmp_file, SDL_BLENDMODE_BLEND); 

  /* Clean up surface */
  SDL_DestroySurface(projectile_surface);
}

void load_bullet_1_assets(Projectile_assets *projectile) {
  SDL_FRect rect = {26.0f, 27.0f, 3.0f, 3.0f};
  projectile->bullet_1 = rect;  
}

void load_bullet_2_assets(Projectile_assets *projectile) {       
  SDL_FRect rect = {4.0f, 4.0f, 1.0f, 1.0f};
  projectile->bullet_2 = rect;  
}

void load_bullet_3_assets(Projectile_assets *projectile) {
  SDL_FRect rect = {19.0f, 19.0f, 2.0f, 2.0f};
  projectile->bullet_3 = rect;  /* Bug fix: Was incorrectly assigning to bullet_2 */
}
