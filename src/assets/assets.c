#include "assets.h"
#include "assets/background_assets.h"
#include "assets/enemy_assets.h"
#include "assets/spaceship_assets.h"
#include "assets/ui_assets.h"
#include "assets/miscellaneous_assets.h"
#include "assets/ttf_assets.h"

/* Global assets variable */
Assets assets;

void load_assets(SDL_Renderer *renderer) {
  /* Load all asset categories */
  load_background_assets(renderer, &assets.background);
  load_enemy_assets(renderer, &assets.enemy);
  load_misc_assets(renderer, &assets.misc);
  load_projectile_assets(renderer, &assets.projectile);
  load_spaceship_assets(renderer, &assets.spaceship);
  load_ttf_assets(renderer, &assets.ttf);
  load_ui_assets(renderer, &assets.ui);
}

void destroy_assets(Assets *assets) {
  /* Clean up and destroy all texture resources */
  
  /* Background textures */
  if (assets->background.bmp_file) {
    SDL_DestroyTexture(assets->background.bmp_file);
  }
  
  /* Enemy textures */
  if (assets->enemy.bmp_file) {
    SDL_DestroyTexture(assets->enemy.bmp_file);
  }
  
  /* Miscellaneous textures */
  if (assets->misc.bmp_file) {
    SDL_DestroyTexture(assets->misc.bmp_file);
  }
  if (assets->misc.bmp_file_2) {
    SDL_DestroyTexture(assets->misc.bmp_file_2);
  }
  
  /* Projectile textures */
  if (assets->projectile.bmp_file) {
    SDL_DestroyTexture(assets->projectile.bmp_file);
  }
  
  /* Spaceship textures */
  if (assets->spaceship.bmp_file) {
    SDL_DestroyTexture(assets->spaceship.bmp_file);
  }
  if (assets->spaceship.bmp_file_2) {
    SDL_DestroyTexture(assets->spaceship.bmp_file_2);
  }
  
  /* Text/font resources */
  if (assets->ttf.space) {
    SDL_DestroyTexture(assets->ttf.space);
  }
  if (assets->ttf.invaders) {
    SDL_DestroyTexture(assets->ttf.invaders);
  }
  if (assets->ttf.player_2_inactive) {
    SDL_DestroyTexture(assets->ttf.player_2_inactive);
  }
  if (assets->ttf.play) {
    SDL_DestroyTexture(assets->ttf.play);
  }
  if (assets->ttf.settings) {
    SDL_DestroyTexture(assets->ttf.settings);
  }
  if (assets->ttf.exit) {
    SDL_DestroyTexture(assets->ttf.exit);
  }
  if (assets->ttf.font) {
    TTF_CloseFont(assets->ttf.font);
  }
  
  /* UI textures */
  if (assets->ui.bmp_file) {
    SDL_DestroyTexture(assets->ui.bmp_file);
  }
  if (assets->ui.bmp_file_2) {
    SDL_DestroyTexture(assets->ui.bmp_file_2);
  }
  
  /* Shut down TTF subsystem */
  TTF_Quit();
}
