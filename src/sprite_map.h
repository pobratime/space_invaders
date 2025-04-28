#ifndef SPRITE_MAP_H
#define SPRITE_MAP_H

#include <SDL3/SDL.h>

typedef struct{
  SDL_Texture *texture;
  float y_level;
  float scroll_speed;
}Background;

typedef struct{
  SDL_FRect scoreboard;
  SDL_FRect level;
}UI_sprites;

typedef struct{
  SDL_FRect idle_rect;
  SDL_FRect steering_left_rect;
  SDL_FRect steering_right_rect;
  SDL_FRect bullet_rect;
}Player_sprites;

typedef struct{
  SDL_FRect enemy_1_idle_rect;
  SDL_FRect enemy_1_shooting_rect;
  SDL_FRect enemy_1_bullet_rect;

  SDL_FRect enemy_2_idle_rect;
  SDL_FRect enemy_2_shooting_rect;
  SDL_FRect enemy_3_idle_rect;
  SDL_FRect enemy_3_shooting_rect;
  SDL_FRect enemy_4_idle_rect;
  SDL_FRect enemy_4_shooting_rect;
  SDL_FRect enemy_5_idle_rect;
  SDL_FRect enemy_5_shooting_rect;
  SDL_FRect enemy_6_idle_rect;
  SDL_FRect enemy_6_shooting_rect;
  SDL_FRect enemy_7_idle_rect;
  SDL_FRect enemy_7_shooting_rect;
  SDL_FRect enemy_8_idle_rect;
  SDL_FRect enemy_8_shooting_rect;
}Enemy_sprites;

typedef struct{
  SDL_FRect mini_boss_1_rect;
}Mini_boss_stripes;

typedef struct{
  SDL_FRect boss_1_rect;
}Boss_stripes;

typedef struct{
  SDL_Texture *spritesheet;
  Background background;
  UI_sprites ui_sprites;
  Enemy_sprites enemy_stripes;
  Mini_boss_stripes mini_boss_stripes;
  Boss_stripes boss_stripes;
  Player_sprites player_sprites;
}Assets;

extern Assets sprite_map;

// basic functionality
int load_assets(SDL_Renderer *renderer);
void load_sprite_rects(void);

// player rects
void load_player_sprites(void);

void load_player_idle_rect(void);
void load_player_steering_left_rect(void);
void load_player_steering_right_rect(void);
void load_player_bullet_rect(void);

// ui elements rects
void load_scoreboard_rect(void);
void load_ui_elemments(void);
void load_level_rect(void);


// enemy rects
void load_enemy_sprites(void);

void load_enemy_1_idle_rect(void);
void load_enemy_1_shooting_rect(void);
void load_enemy_1_bullet_rect(void);

void load_enemy_2_idle_rect(void);
void load_enemy_2_shooting_rect(void);

void load_enemy_3_idle_rect(void);
void load_enemy_3_shooting_rect(void);

void load_enemy_4_idle_rect(void);
void load_enemy_4_shooting_rect(void);

void load_enemy_5_idle_rect(void);
void load_enemy_5_shooting_rect(void);

void load_enemy_6_idle_rect(void);
void load_enemy_6_shooting_rect(void);

void load_enemy_7_idle_rect(void);
void load_enemy_7_shooting_rect(void);

void load_enemy_8_idle_rect(void);
void load_enemy_8_shooting_rect(void);


#endif
