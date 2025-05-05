#include "game/update/update_pause_state.h"
#include "game/game_states.h"
#include "assets/assets.h"

void handle_paused_state(Game *game, float delta_time, SDL_Scancode pressed_key) {
  switch(pressed_key) {
    case(SDL_SCANCODE_UP): {
      game->pause_state.current_pause_button -= 1;
      if(game->pause_state.current_pause_button < 0) 
        game->pause_state.current_pause_button = 2;
      break;
    }
    case(SDL_SCANCODE_DOWN): {
      game->pause_state.current_pause_button += 1;
      if(game->pause_state.current_pause_button > 2) 
        game->pause_state.current_pause_button = 0;
      break;
    }
    case(SDL_SCANCODE_SPACE): {
      switch(game->pause_state.current_pause_button) {
        case 0: // Resume
          game->data_dynamic.state = GAME_STATE_PLAYING;
          SDL_HideWindow(game->pause_window);
          break;
        case 1: // Settings
          game->data_dynamic.state = GAME_STATE_OPTIONS;
          SDL_HideWindow(game->pause_window);
          break;
        case 2: // Main Menu
          game->data_dynamic.state = GAME_STATE_MENU;
          SDL_HideWindow(game->pause_window);
          break;
      }
      default: break;
    }
    case(SDL_SCANCODE_ESCAPE):
    case(SDL_SCANCODE_P): {
      // Return to playing when P is pressed again
      game->data_dynamic.state = GAME_STATE_PLAYING;
      SDL_HideWindow(game->pause_window);
      break;
    }
  }
}
