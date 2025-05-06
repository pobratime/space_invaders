#include "update_menu_state.h"
#include "game/game.h"
#include "game/game_states.h"
#include "assets/assets.h"
#include <stdlib.h>

void handle_menu_state(Game *game, float delta_time, SDL_Scancode pressed_key){

  switch(pressed_key){
    case(SDL_SCANCODE_DOWN):{
      if(game->menu_data.current_button >= 3) game->menu_data.current_button = 0;
      else game->menu_data.current_button += 1;
      break;
    }
    case(SDL_SCANCODE_UP):{
      if(game->menu_data.current_button <= 0) game->menu_data.current_button = 3;
      else game->menu_data.current_button -= 1;
      break;
    }
    case(SDL_SCANCODE_SPACE):{
      switch(game->menu_data.current_button){
        case(0): 
          init_game_data(game);
          game->data_dynamic.state = GAME_STATE_PLAYING;
          break;
        case(1):
          game->options_data.current_button = 0; 
          game->data_dynamic.state = GAME_STATE_OPTIONS; 
          break;
        case(2): 
          game->running = 0;
          break;
        case(3):{
          open_url("https://github.com/pobratime/space_invaders/issues");
          break;
        }
        default: 
          break;
      }
      break;
    }
    default:{
      break;
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