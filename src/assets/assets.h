#ifndef ASSETS_H
#define ASSETS_H

#include "background_assets.h"
#include "enemy_assets.h"
#include "miscellaneous_assets.h"
#include "projectiles_assets.h"
#include "spaceship_assets.h"
#include "ttf_assets.h"
#include "ui_assets.h"

/**
 * Main assets structure containing all game assets
 */
typedef struct {
  Background_assets background;     /* Background layers and textures */
  Enemy_assets enemy;               /* Enemy sprites and textures */
  Misc_assets misc;                 /* Miscellaneous game elements */
  Projectile_assets projectile;     /* Projectile/bullet sprites */
  Spaceship_assets spaceship;       /* Player spaceship sprites */
  TTF_assets ttf;                   /* Text and font assets */
  Ui_assets ui;                     /* User interface elements */
} Assets;

/* Global assets instance */
extern Assets assets;

/* Function declarations */
void load_assets(SDL_Renderer *renderer);
void destroy_assets(Assets *assets);

#endif /* ASSETS_H */
