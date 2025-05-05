#include "update_menu_state.h"
#include "game/game_states.h"
#include "assets/assets.h"

void handle_menu_state(Game *game, float delta_time, SDL_Scancode pressed_key){

  switch(pressed_key){
    case(SDL_SCANCODE_DOWN):{
      game->menu_state.current_menu_button += 1;
      if(game->menu_state.current_menu_button > 1) game->menu_state.current_menu_button = -1;
      break;
    }
    case(SDL_SCANCODE_UP):{
      game->menu_state.current_menu_button -= 1;
      if(game->menu_state.current_menu_button < -1) game->menu_state.current_menu_button = 1;
      break;
    }
    case(SDL_SCANCODE_SPACE):{
      switch(game->menu_state.current_menu_button){
        case(-1): 
          game->data_dynamic.state = GAME_STATE_PLAYING;
          break;
        case(0): 
          game->data_dynamic.state = GAME_STATE_OPTIONS; 
          break;
        case(1): 
          // TODO
        break;
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
  switch(game->menu_state.current_menu_button){
    case(-1):{
      game->data_dynamic.settings_button_state = assets.ui.settings_button.idle;
      game->data_dynamic.play_button_state = assets.ui.play_button.selected;
      game->data_dynamic.exit_button_state = assets.ui.exit_button.idle;
      break; 
    }
    case(0):{
      game->data_dynamic.settings_button_state = assets.ui.settings_button.selected;
      game->data_dynamic.play_button_state = assets.ui.play_button.idle;
      game->data_dynamic.exit_button_state = assets.ui.exit_button.idle;
      break; 
    }
    case(1):{
      game->data_dynamic.settings_button_state = assets.ui.settings_button.idle;
      game->data_dynamic.play_button_state = assets.ui.play_button.idle;
      game->data_dynamic.exit_button_state = assets.ui.exit_button.selected;
      break;
    }
    default: break;
  }
}

void blink_buttons(Game *game){

}
