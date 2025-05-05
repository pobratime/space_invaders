#include "game/update/game_update.h"
#include "execution.h"
#include "game/update/update_menu_state.h"
#include "game/game.h"
#include "game/update/update_playing_state.h"
#include "game/update/update_pause_state.h"

void update_game(Game *game, float delta_time, SDL_Scancode pressed_key) {

  switch (game->data_dynamic.state) {
  case (GAME_STATE_MENU): {
    handle_menu_state(game, delta_time, pressed_key);
    break;
  }
  case (GAME_STATE_PLAYING): {
    handle_playing_state(game, delta_time, pressed_key);
    break;
  }
  case (GAME_STATE_PAUSED): {
    handle_paused_state(game, delta_time, pressed_key);
    break;
  }
  case (GAME_STATE_OPTIONS): {
    break;
  }
  case (GAME_STATE_GAME_OVER): {
    break;
  }
  case (GAME_STATE_WELCOME): {
    break;
  }
  }

  update_background(game, delta_time);
}

void update_background(Game *game, float delta_time){

  game->data_dynamic.background_y_level += 50.0f * delta_time;
  if(game->data_dynamic.background_y_level >= 720.0f) game->data_dynamic.background_y_level = 0.0f;
  
}
