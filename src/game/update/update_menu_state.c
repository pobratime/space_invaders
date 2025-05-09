#include "update_menu_state.h"
#include "game/game.h"
#include "game/game_states.h"
#include "assets/assets.h"
#include <stdlib.h>
#include "game/update/update_audio.h"

void handle_menu_state(Game *game, float delta_time, bool key_states[]){
  // Update cooldown timer
  game->menu_data.input_cooldown -= delta_time;
  
  // Only process input if cooldown has expired
  if (game->menu_data.input_cooldown <= 0.0f) {
    if(key_states[SDL_SCANCODE_DOWN]){
      play_button_selection_sound(game, delta_time);
      if(game->menu_data.current_button >= 3) game->menu_data.current_button = 0;
      else game->menu_data.current_button += 1;
      game->menu_data.input_cooldown = 0.2f; // Set cooldown to prevent rapid changes
    }
    else if(key_states[SDL_SCANCODE_UP]){
      play_button_selection_sound(game, delta_time);
      if(game->menu_data.current_button <= 0) game->menu_data.current_button = 3;
      else game->menu_data.current_button -= 1;
      game->menu_data.input_cooldown = 0.2f; // Set cooldown to prevent rapid changes
    }
    else if(key_states[SDL_SCANCODE_SPACE]){
      game->menu_data.input_cooldown = 0.2f; // Set cooldown for space key too
      switch(game->menu_data.current_button){
        case(0): 
          play_button_clicked_sound(game, delta_time);
          init_game_data(game);
          game->data_dynamic.state = GAME_STATE_PLAYING;
          break;
        case(1):
          play_button_clicked_sound(game, delta_time);
          game->options_data.current_button = 0; 
          game->data_dynamic.state = GAME_STATE_OPTIONS; 
          break;
        case(2): 
          play_button_clicked_sound(game, delta_time);
          game->running = 0;
          break;
        case(3):
          play_button_clicked_sound(game, delta_time);
          open_url("https://github.com/pobratime/space_invaders/issues");
          break;
        default: 
          break;
      }
    }
  }

  outlay_selected_button(game);
}

void outlay_selected_button(Game *game){
  
  game->menu_data.settings_button_state = assets.ui.settings_button.idle;
  game->menu_data.play_button_state = assets.ui.play_button.idle;
  game->menu_data.exit_button_state = assets.ui.exit_button.idle;
  game->menu_data.feedback_button_state = assets.ui.feedback_button.idle;

  switch(game->menu_data.current_button){
    case(0):{
      game->menu_data.play_button_state = assets.ui.play_button.selected; 
      break;
    }
    case(1):{
      game->menu_data.settings_button_state = assets.ui.settings_button.selected;
      break; 
    }
    case(2):{
      game->menu_data.exit_button_state = assets.ui.exit_button.selected;
      break; 
    }
    case(3):{
      game->menu_data.feedback_button_state = assets.ui.feedback_button.selected;
      break;
    }
    default: 
      break;
  }
}

void open_url(const char *url) {
  #ifdef _WIN32
      char command[256];
      snprintf(command, sizeof(command), "start %s", url);
      system(command);
  #elif __APPLE__
      char command[256];
      snprintf(command, sizeof(command), "open %s", url);
      system(command);
  #elif __linux__
      char command[256];
      snprintf(command, sizeof(command), "xdg-open %s", url);
      system(command);
  #else
  #endif
}