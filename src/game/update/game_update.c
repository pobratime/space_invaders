#include "game/update/game_update.h"
#include "execution.h"
#include "game/game_states.h"
#include "game/update/update_menu_state.h"
#include "game/game.h"
#include "game/update/update_playing_state.h"
#include "game/update/update_pause_state.h"
#include "game/update/update_settings_state.h"
#include "game/update/update_audio.h"

void update_game(Game *game, float delta_time, bool key_states[]) {

  switch (game->data_dynamic.state) {
  case (GAME_STATE_MENU): {
    handle_menu_state(game, delta_time, key_states);
    game->last_state = GAME_STATE_MENU;
    break;
  }
  case (GAME_STATE_PLAYING): {
    handle_playing_state(game, delta_time, key_states);
    break;
  }
  case (GAME_STATE_PAUSED): {
    handle_paused_state(game, delta_time, key_states);
    game->last_state = GAME_STATE_PAUSED;
    break;
  }
  case (GAME_STATE_OPTIONS): {
    handle_settings_state(game, delta_time, key_states);
    break;
  }
  case (GAME_STATE_GAME_OVER): {
    // TOOD
    break;
  }
  case (GAME_STATE_WELCOME): {
    // TODO
    break;
  }
  }

  handle_audio(game, delta_time);
  update_background(game, delta_time);
}

void update_background(Game *game, float delta_time){

  game->data_dynamic.background_y_level += 100.0f * delta_time;
  if(game->data_dynamic.background_y_level >= 1050.0f * game->options_data.y_scale) game->data_dynamic.background_y_level = 0.0f;
  
}
