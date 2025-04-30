#include "enemy_assets.h"

void load_enemy_assets(SDL_Renderer *renderer, Enemy_assets *enemy){

  // TMP
  SDL_Surface *enemy_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/spaceships.bmp");
  // SDL_Surface *enemy_surface = SDL_LoadBMP("src/assets/spaceships.bmp");
  if(enemy_surface == NULL)
    fprintf(stderr, "Error while loading a enemy BMP file: %s\n", SDL_GetError());

  enemy->bmp_file = SDL_CreateTextureFromSurface(renderer, enemy_surface);  
  if(enemy->bmp_file == NULL)
    fprintf(stderr, "Error while creating a enemy texture from a BMP file: %s\n", SDL_GetError());

  load_enemy_1_assets(enemy);
  load_enemy_2_assets(enemy);
  load_boss_1_assets(enemy);

  SDL_SetTextureScaleMode(enemy->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(enemy->bmp_file, SDL_BLENDMODE_BLEND);

  SDL_DestroySurface(enemy_surface);
}

void load_enemy_1_assets(Enemy_assets *enemy){
  SDL_FRect rect = {34.0f, 2.0f, 4.0f, 5.0f};
  enemy->enemy_1.rect = rect;
}

void load_enemy_2_assets(Enemy_assets *enemy){
  SDL_FRect rect = {40.0f, 2.0f, 6.0f, 5.0f};
  enemy->enemy_2.rect = rect;
}

void load_boss_1_assets(Enemy_assets *enemy) {
  SDL_FRect rect = {
    32.0f, 48.0f, 16.0f, 16.0f
  };
  enemy->boss.boss_1 = rect;
}