#ifndef SPRITE_MAP_H
#define SPRITE_MAP_H

#include <SDL3/SDL.h>

typedef struct{
  // all textures
  SDL_Texture *spritesheet;

  // player textures
  SDL_FRect player_normal_rect;
  SDL_FRect player_steering_left_rect;
  SDL_FRect player_steering_right_rect;

  // background textures
  SDL_FRect background_rect;

  // enemy textures
  SDL_FRect enemy_1_idle_rect;
  SDL_FRect enemy_1_shooting_rect;
  // other
  // todo

}Sprite_map;

extern Sprite_map sprite_map;

// basic functionality
int init_spritesheet(SDL_Renderer *renderer);
void load_sprite_rects(void);

// player rects
void load_player_normal_rect(void);
void load_player_steering_left_rect(void);
void load_player_steering_right_rect(void);

// background rects
void load_background_rect(void);

// enemy rects
void load_enemy_1_idle_rect(void);
void load_enemy_1_shooting_rect(void);

#endif
