#include "game.h"
#include "game/game_states.h"
#include "player.h"
#include "assets/assets.h"
#include "level/level.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void init_game_data(Game *game){

  // This is the game data that wont be changed trough the game exectuion
  init_random_game_seed(game);
  game->data_const.background_scroll_speed = 30.0f;
  game->data_const.levels = malloc(sizeof(Level) * 10);

  game->menu_state.current_menu_button = -1;

  // This si the game data that will be changed trough the game exectuon and is now set temp
  game->data_dynamic.state = GAME_STATE_MENU; // change later
  game->data_dynamic.background_y_level = 0.0f; // Initialize background position
  game->data_dynamic.current_player_rect = assets.spaceship.spaceship_1.idle;
  game->data_dynamic.current_emission_1 = assets.misc.emission_ship_1.em_1;
  game->data_dynamic.current_emission_2 = assets.misc.emission_ship_1.em_4;

  init_player(&game->player);

  // TEMP
  game->player.movement.x = 640;
  game->player.movement.y = 630;
}

void init_random_game_seed(Game *game){
  unsigned int tmp_seed = (unsigned int)time(NULL);
  tmp_seed ^= (unsigned int)SDL_GetTicks();
  tmp_seed ^= (uintptr_t)&tmp_seed;
  srand(tmp_seed);
  game->data_const.game_seed = rand();
}
