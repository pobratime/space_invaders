#include "game.h"
#include "game/game_states.h"
#include "player.h"
#include "assets/assets.h"
#include "level/level.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void create_game(Game *game){  
  
  init_random_game_seed(game);
  game->data_const.levels = malloc(sizeof(Level) * 10);
  game->options_data.current_resolution_int = 1;
  game->running = 1;

  // MOVE THIS TO INIT PLAYER
  game->player.bullets = malloc(sizeof(Bullet) * 10);
  if(game->player.bullets == NULL){
    SDL_Log("error while allocating bullets array: %s\n", SDL_GetError());
  }
  for(int i = 0; i < 10; i++){
    game->player.bullets[i].active = 0;
  }
  
  game->options_data.current_resolution_int = 1;

  game->options_data.music_level = 25;
  game->options_data.sound_level = 50;
}

void init_game_data(Game *game){
  
  // This is the game data that wont be changed trough the game exectuion
  game->menu_data.current_button = 0;
  game->menu_data.input_cooldown = 0.0f;
  
  game->pause_data.current_button = 0;
  game->pause_data.input_cooldown = 0.0f;

  // This si the game data that will be changed trough the game exectuon and is now set temp
  game->data_dynamic.state = GAME_STATE_MENU; // change later
  game->data_dynamic.background_y_level = 0.0f; // Initialize background position

  game->options_data.current_button = 0;
  game->options_data.input_cooldown = 0.0f;
  
  init_player(&game->player);
}

void init_random_game_seed(Game *game){
  unsigned int tmp_seed = (unsigned int)time(NULL);
  tmp_seed ^= (unsigned int)SDL_GetTicks();
  tmp_seed ^= (uintptr_t)&tmp_seed;
  srand(tmp_seed);
  game->data_const.game_seed = rand();
}

void init_settings(Game *game){
  // TODO LOAD BOXES
  
  game->options_data.current_resolution_int = 1;
  game->options_data.current_x = 1680.0f;
  game->options_data.current_y = 1050.0f;

  game->options_data.music_level = 10;
  game->options_data.sound_level = 10;
  // TODO REST
}
