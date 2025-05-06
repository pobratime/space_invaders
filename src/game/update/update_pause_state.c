#include "game/update/update_pause_state.h"
#include "game/game_states.h"
#include "assets/assets.h"

void handle_paused_state(Game *game, float delta_time, SDL_Scancode pressed_key) {
  // SDL_ShowWindow(game->pause_data.pause_window);  // Removed as we're not using separate window
  switch(pressed_key) {
    case(SDL_SCANCODE_UP): {
      if(game->pause_data.current_button == 0) game->pause_data.current_button = 2;
      else game->pause_data.current_button -= 1; 
      break;
    }
    case(SDL_SCANCODE_DOWN): {
      if(game->pause_data.current_button == 2) game->pause_data.current_button = 0;
      else game->pause_data.current_button += 1; 
      break;
    }
    case(SDL_SCANCODE_SPACE): {
      switch(game->pause_data.current_button) {
        case(0): // Resume
          game->data_dynamic.state = GAME_STATE_PLAYING;
          // SDL_HideWindow(game->pause_data.pause_window);  // Removed as we're not using separate window
          break;
        case(1): // Settings
          game->options_data.current_button = 0;
          game->last_state = GAME_STATE_PAUSED;
          game->data_dynamic.state = GAME_STATE_OPTIONS;
          // SDL_HideWindow(game->pause_data.pause_window);  // Removed as we're not using separate window
          break;
        case(2): // Main Menu
        // TODO CREATE A CONFIRM MENU
          game->data_dynamic.state = GAME_STATE_MENU;
          // SDL_HideWindow(game->pause_data.pause_window);  // Removed as we're not using separate window
          break;
      }
      break;  // Add missing break statement for SPACE case
    }
    case(SDL_SCANCODE_ESCAPE):
    case(SDL_SCANCODE_P): {
      // Return to playing when P or ESC is pressed again
      game->data_dynamic.state = GAME_STATE_PLAYING;
      // SDL_HideWindow(game->pause_data.pause_window);  // Removed as we're not using separate window
      break;
    }
    default: break;
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