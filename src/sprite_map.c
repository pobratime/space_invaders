#include "sprite_map.h"
#include <SDL3/SDL.h>

Assets sprite_map;

// Function that will load all the assets needed to run the game
int load_assets(SDL_Renderer *renderer){

  // Loading a bmp file which contains all the textures
  SDL_Surface *surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/assets/ass2.bmp");
  if(surface == NULL){
    fprintf(stderr, "Error while loading spritesheet: %s\n", SDL_GetError());
    return -1;
  }
  // Creating a texture out of a loaded surface which we use later to crop out specific parts to render specific textures
  sprite_map.spritesheet = SDL_CreateTextureFromSurface(renderer, surface);
  if(sprite_map.spritesheet == NULL){
    fprintf(stderr, "Error while applying spritesheet texture from surface: %s\n", SDL_GetError());
    return -1;
  }

  // Loading a bmp file which containts a background texture
  SDL_Surface *background_surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/assets/background.bmp");
  if(background_surface == NULL){
    fprintf(stderr, "Error while loading background texture: %s\n", SDL_GetError());
    return -1;
  }
  // Creating a texture from surface for backgound alongside with setting other background params which are used for the animation
  sprite_map.background.texture = SDL_CreateTextureFromSurface(renderer, background_surface);
  if(sprite_map.background.texture == NULL){
    fprintf(stderr, "Error while applying background texture from surface: %s\n", SDL_GetError()); 
  }  
  sprite_map.background.scroll_speed = 30.0f;
  sprite_map.background.y_level = 0.0f;

  // Scaling so that the texture loaded from a BMP file dont appear blurry while playing the game
  SDL_SetTextureScaleMode(sprite_map.spritesheet, SDL_SCALEMODE_NEAREST);
  SDL_SetTextureBlendMode(sprite_map.spritesheet, SDL_BLENDMODE_BLEND);
  // Function that will create specifc FRects
  load_sprite_rects();  

  // Destroying surfaces we dont use anymore
  SDL_DestroySurface(surface);
  SDL_DestroySurface(background_surface);

  return 1;
}

// Loading/Extracting specifc FRects
void load_sprite_rects(void) {
  load_player_sprites();
  load_enemy_sprites();
  load_ui_elemments();
  load_enemy_sprites();
}

void load_ui_elemments(void){
  load_scoreboard_rect();
  load_level_rect();
}

// Loading/Extracting all the textures required for the player
void load_player_sprites(void){
  load_player_idle_rect();
  load_player_steering_left_rect();
  load_player_steering_right_rect();
  load_player_bullet_rect();
}

// Loading/Extracting all the textures required for enemy n1 
void load_enemy_sprites(void){
  load_enemy_1_idle_rect();
  load_enemy_1_shooting_rect();
  load_enemy_1_bullet_rect();
}

// ALL THE FUNCTION BELOW ARE USED TO EXTRACT THE SPECIFIC PARTS OUT OF SPRITE_MAP

void load_player_idle_rect(void){
  SDL_FRect rect;
  rect.x = 0; rect.y = 1; rect.w = 8; rect.h = 7;
  sprite_map.player_sprites.idle_rect = rect;
}

void load_player_steering_left_rect(void){
  SDL_FRect rect;
  rect.x = 9; rect.y = 1; rect.w = 7; rect.h = 7;
  sprite_map.player_sprites.steering_left_rect = rect;
}

void load_player_steering_right_rect(void){
  SDL_FRect rect;
  rect.x = 17; rect.y = 1; rect.w = 7; rect.h = 7;
  sprite_map.player_sprites.steering_right_rect = rect;
}

void load_player_bullet_rect(void){
  SDL_FRect rect;
  rect.x = 2; rect.y = 16; rect.w = 2; rect.h = 6;
  sprite_map.player_sprites.bullet_rect = rect;
}

void load_scoreboard_rect(void){
  SDL_FRect rect;
  rect.x = 97; rect.y = 105; rect.w = 30; rect.h = 20;
  sprite_map.ui_sprites.scoreboard = rect;
}

void load_level_rect(void){
  SDL_FRect rect;
  rect.x = 1; rect.y = 105; rect.w = 30; rect.h = 20;
  sprite_map.ui_sprites.level = rect;
}

void load_enemy_1_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
  sprite_map.enemy_stripes.enemy_1_idle_rect = rect;
}

void load_enemy_1_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
  sprite_map.enemy_stripes.enemy_1_shooting_rect = rect;
}

void load_enemy_1_bullet_rect(void){
  SDL_FRect rect;
  rect.x = 11; rect.y = 50; rect.w = 5; rect.h = 3;
  sprite_map.enemy_stripes.enemy_1_bullet_rect = rect;
}

void load_enemy_2_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
}

void load_enemy_2_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
}

void load_enemy_3_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
}

void load_enemy_3_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
}

void load_enemy_4_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
}

void load_enemy_4_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
}

void load_enemy_5_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
}

void load_enemy_5_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
}

void load_enemy_6_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
}

void load_enemy_6_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
}

void load_enemy_7_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
}

void load_enemy_7_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
}

void load_enemy_8_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
}

void load_enemy_8_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
}

