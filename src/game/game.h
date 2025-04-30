#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "player.h"
#include "level/level.h"
#include "game_states.h"

typedef struct{
  int current_menu_button;
}Menu_state;

typedef struct{
  float background_scroll_speed;
  Level *levels;
  unsigned int game_seed;
}Game_data_const;

typedef struct{
  Game_state state;
  Level current_level;
  float background_y_level;
  SDL_FRect current_player_rect;

  SDL_FRect current_emission_1;
  SDL_FRect current_emission_2;

  SDL_FRect settings_button_state;
  SDL_FRect play_button_state;
  SDL_FRect exit_button_state;

}Game_data_dynamic;

typedef struct{
  // Main game renderer and window
  SDL_Window *window;
  SDL_Renderer *renderer;

  Menu_state menu_state;

  // Game data
  Game_data_dynamic data_dynamic;
  Game_data_const data_const;

  // TODO
  Player player;
}Game;

void init_game_data(Game *game);
void init_random_game_seed(Game *game);

#endif
