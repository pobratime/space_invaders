#ifndef ASSETS_H
#define ASSETS_H

#include "SDL3/SDL.h"
#include "enemy_assets.h"
#include "ui_assets.h"
#include "spaceship_assets.h"
#include "projectiles_assets.h"
#include "background_assets.h"
#include "miscellaneous_assets.h"

typedef struct{
  Enemy_assets enemy;
  Ui_assets ui;
  Spaceship_assets spaceship;
  Projectile_assets projcetiles;
  Background_assets background;
  Misc_assets misc;
}Assets;

extern Assets assets;

void load_assets(SDL_Renderer *renderer);

#endif
