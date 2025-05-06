#include "enemy_assets.h"
#include <stdio.h>

void load_enemy_assets(SDL_Renderer *renderer, Enemy_assets *enemy) {
  /* Load enemy bitmap */
  SDL_Surface *enemy_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/spaceships.bmp");
  
  /* Check if surface loaded correctly */
  if (enemy_surface == NULL) {
    fprintf(stderr, "Error loading enemy BMP file: %s\n", SDL_GetError());
    return;
  }

  /* Create texture from surface */
  enemy->bmp_file = SDL_CreateTextureFromSurface(renderer, enemy_surface);  
  
  /* Check if texture created correctly */
  if (enemy->bmp_file == NULL) {
    fprintf(stderr, "Error creating enemy texture: %s\n", SDL_GetError());
    SDL_DestroySurface(enemy_surface);
    return;
  }

  /* Load specific enemy assets */
  load_enemy_1_assets(enemy);
  load_enemy_2_assets(enemy);
  load_boss_1_assets(enemy);

  /* Configure texture properties */
  SDL_SetTextureScaleMode(enemy->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(enemy->bmp_file, SDL_BLENDMODE_BLEND);

  /* Clean up surface */
  SDL_DestroySurface(enemy_surface);
}

void load_enemy_1_assets(Enemy_assets *enemy) {
  /* Define enemy type 1 appearance */
  SDL_FRect rect = {34.0f, 2.0f, 4.0f, 5.0f};
  enemy->enemy_1.rect = rect;
}

void load_enemy_2_assets(Enemy_assets *enemy) {
  /* Define enemy type 2 appearance */
  SDL_FRect rect = {40.0f, 2.0f, 6.0f, 5.0f};
  enemy->enemy_2.rect = rect;
}

void load_boss_1_assets(Enemy_assets *enemy) {
  /* Define boss enemy appearance */
  SDL_FRect rect = {32.0f, 48.0f, 16.0f, 16.0f};
  enemy->boss.boss_1 = rect;
}
