#include "assets.h"
#include "assets/background_assets.h"
#include "assets/enemy_assets.h"
#include "assets/spaceship_assets.h"
#include "assets/ui_assets.h"
#include "assets/miscellaneous_assets.h"
#include "assets/ttf_assets.h"

Assets assets;

void load_assets(SDL_Renderer *renderer){
  
  load_ui_assets(renderer, &assets.ui);
  load_spaceship_assets(renderer, &assets.spaceship);
  load_enemy_assets(renderer, &assets.enemy);
  load_background_assets(renderer, &assets.background);
  load_misc_assets(renderer, &assets.misc);
  load_ttf_assets(renderer, &assets.ttf);  
}
