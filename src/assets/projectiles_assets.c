#include "projectiles_assets.h"

void load_projectile_assets(SDL_Renderer *renderer, Projectile_assets *projectile){

  // TMP
  SDL_Surface *projectile_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/src/assets_bmp/projectiles.bmp");

  // SDL_Surface *projectile_surface = SDL_LoadBMP("src/assets/projectiles.bmp");
  if(projectile_surface == NULL)
    fprintf(stderr, "Error while loading a projectile BMP file: %s\n", SDL_GetError());

  projectile->bmp_file = SDL_CreateTextureFromSurface(renderer, projectile_surface);
  if(projectile->bmp_file == NULL)
    fprintf(stderr, "Error while creating a projectile texture from a BMP file: %s\n", SDL_GetError());

  load_bullet_1_assets(projectile);
  load_bullet_2_assets(projectile);
  load_bullet_3_assets(projectile);

  SDL_SetTextureScaleMode(projectile->bmp_file, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(projectile->bmp_file, SDL_BLENDMODE_BLEND); 

  SDL_DestroySurface(projectile_surface);
}

void load_bullet_1_assets(Projectile_assets *projectile){
  SDL_FRect rect = {26.0f, 27.0f, 3.0f, 3.0f};
  projectile->bullet_1 = rect;  
}

void load_bullet_2_assets(Projectile_assets *projectile){       
  SDL_FRect rect = {4.0f, 4.0f, 1.0f, 1.0f};
  projectile->bullet_2 = rect;  
}

void load_bullet_3_assets(Projectile_assets *projectile){
  SDL_FRect rect = {19.0f, 19.0f, 2.0f, 2.0f};
  projectile->bullet_2 = rect;  
}
