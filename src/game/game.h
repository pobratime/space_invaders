#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "player.h"
#include "level/level.h"
#include "game_states.h"

typedef struct{

}Playing_data;

typedef struct{
  int current_button;

  SDL_FRect settings_button_state;
  SDL_FRect play_button_state;
  SDL_FRect exit_button_state;
  SDL_FRect feedback_button_state;

}Menu_data;

typedef struct{
  int current_button;

  unsigned int sound_level;
  unsigned int music_level;

  unsigned int current_resolution_int;

  SDL_FRect cur_1920x1080;
  SDL_FRect cur_1680x1050;
  SDL_FRect cur_1280x800;
  SDL_FRect cur_exit;

  SDL_FRect cur_music;
  float cur_music_x;
  SDL_FRect cur_sound;
  float cur_sound_x;

  float current_x;
  float current_y;

  float x_scale;
  float y_scale;
}Options_data;

typedef struct{
  int current_button;

  SDL_FRect resume_button_state;
  SDL_FRect settings_button_state;
  SDL_FRect main_menu_button_state;

}Pause_data;

typedef struct{
  Level *levels;
  unsigned int game_seed;
}Game_data_const;

typedef struct{
  Game_state state;
  Level current_level;
  float background_y_level;
}Game_data_dynamic;

typedef struct{
  // Main game renderer and window
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Window *warning_window;
  
  // Game data
  Game_data_dynamic data_dynamic;
  Game_data_const data_const;

  // Specif data
  Options_data options_data;
  Menu_data menu_data;
  Pause_data pause_data;
  Playing_data playing_data;

  int running;
  Game_state last_state;

  // TODO
  Player player;
}Game;

void init_game_data(Game *game);
void init_settings(Game *game);
void init_random_game_seed(Game *game);
void create_game(Game *game);

#endif
