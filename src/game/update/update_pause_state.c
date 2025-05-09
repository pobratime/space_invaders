#include "game/update/update_pause_state.h"
#include "game/game_states.h"
#include "assets/assets.h"
#include "game/update/update_audio.h"

void handle_paused_state(Game *game, float delta_time, bool key_states[]) {
  // SDL_ShowWindow(game->pause_data.pause_window);  // Removed as we're not using separate window
  
  // Update cooldown timer
  game->pause_data.input_cooldown -= delta_time;
  
  // Only process input if cooldown has expired
  if (game->pause_data.input_cooldown <= 0.0f) {
    if(key_states[SDL_SCANCODE_UP]){
      play_button_selection_sound(game, delta_time);
      if(game->pause_data.current_button == 0) game->pause_data.current_button = 2;
      else game->pause_data.current_button -= 1; 
      game->pause_data.input_cooldown = 0.2f; // Set cooldown to prevent rapid changes
      
    }else if(key_states[SDL_SCANCODE_DOWN]){
      play_button_selection_sound(game, delta_time);
      if(game->pause_data.current_button == 2) game->pause_data.current_button = 0;
      else game->pause_data.current_button += 1;
      game->pause_data.input_cooldown = 0.2f; // Set cooldown to prevent rapid changes
      
    }else if(key_states[SDL_SCANCODE_SPACE]){
      game->pause_data.input_cooldown = 0.2f; // Set cooldown for space key too

      switch(game->pause_data.current_button) {
        case(0): {// Resume
          play_button_clicked_sound(game, delta_time);
          game->data_dynamic.state = GAME_STATE_PLAYING;
          break;
        }
        case(1): { // Settings
          play_button_clicked_sound(game, delta_time);
          game->options_data.current_button = 0;
          game->options_data.input_cooldown = 0.2f;
          game->last_state = GAME_STATE_PAUSED;
          game->data_dynamic.state = GAME_STATE_OPTIONS;
          break;
        }
        case(2):{ // Main Menu
        // TODO CREATE A CONFIRM MENU
          play_button_clicked_sound(game, delta_time);
          game->data_dynamic.state = GAME_STATE_MENU;
          game->menu_data.input_cooldown = 0.2f;
          break;
        }
        default: break;
      }
    }
  }
  update_pause_button_states(game);
}

void update_pause_button_states(Game *game) {
  // Reset all buttons to idle state first
  game->pause_data.resume_button_state = assets.ui.play_button.idle;
  game->pause_data.settings_button_state = assets.ui.settings_button.idle;
  game->pause_data.main_menu_button_state = assets.ui.exit_button.idle;
  
  // Highlight the selected button
  switch(game->pause_data.current_button) {
    case 0: // Resume
      game->pause_data.resume_button_state = assets.ui.play_button.selected;
      break;
    case 1: // Settings
      game->pause_data.settings_button_state = assets.ui.settings_button.selected;
      break;
    case 2: // Main Menu
      game->pause_data.main_menu_button_state = assets.ui.exit_button.selected;
      break;
  }
}
