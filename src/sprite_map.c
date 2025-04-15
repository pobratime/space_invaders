#include "sprite_map.h"
#include <SDL3/SDL.h>

Sprite_map sprite_map;

int init_spritesheet(SDL_Renderer *renderer){
  SDL_Surface *surface = SDL_LoadBMP("/Users/lukaajdukovic/Desktop/space_invaders/assets/ass2.bmp");
  if(surface == NULL){
    fprintf(stderr, "Error while loading spritesheet: %s\n", SDL_GetError());
    return -1;
  }

  sprite_map.spritesheet = SDL_CreateTextureFromSurface(renderer, surface);
  if(sprite_map.spritesheet == NULL){
    fprintf(stderr, "Error while applying spritesheet texture from surface: %s\n", SDL_GetError());
    return -1;
  }

  SDL_SetTextureScaleMode(sprite_map.spritesheet, SDL_SCALEMODE_NEAREST);
  load_sprite_rects();
  
  SDL_DestroySurface(surface);
  return 1;
}

void load_sprite_rects(void) {
  load_player_normal_rect();
  load_player_steering_left_rect();
  load_player_steering_right_rect();
  load_background_rect();
  load_enemy_1_idle_rect();
  load_enemy_1_shooting_rect();
  // load_enemy_2_rect();
  // load_meteor_1_rect();
}

void load_player_normal_rect(void){
  SDL_FRect rect;
  rect.x = 0; rect.y = 1; rect.w = 8; rect.h = 7;
  sprite_map.player_normal_rect = rect;
}

void load_player_steering_left_rect(void){
  SDL_FRect rect;
  rect.x = 9; rect.y = 1; rect.w = 7; rect.h = 7;
  sprite_map.player_steering_left_rect = rect;
}

void load_player_steering_right_rect(void){
  SDL_FRect rect;
  rect.x = 17; rect.y = 1; rect.w = 7; rect.h = 7;
  sprite_map.player_steering_right_rect = rect;
}

void load_background_rect(void){
  SDL_FRect rect;
  rect.x = 0; rect.y = 0; rect.w = 1; rect.h = 1;
  sprite_map.background_rect = rect;
}

void load_enemy_1_idle_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 0; rect.w = 8; rect.h = 8;
  sprite_map.enemy_1_idle_rect = rect;
}

void load_enemy_1_shooting_rect(void){
  SDL_FRect rect;
  rect.x = 24; rect.y = 8; rect.w = 8; rect.h = 8;
  sprite_map.enemy_1_shooting_rect = rect;
}
