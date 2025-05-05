#include "render_pause.h"
#include "assets/assets.h"

void render_pause(Game *game){
  // Create a semi-transparent background overlay
  // SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 150);
  // SDL_FRect overlay_rect = {340.0f, 220.0f, 200.0f, 200.0f};
  // SDL_RenderFillRect(game->renderer, &overlay_rect);
  
  // Render pause menu header
  // render_pause_header(game);
  
  // Render pause menu items
  render_pause_menu(game);
}

void render_pause_menu(Game *game){
  // Render Resume button
  SDL_FRect resume_rect = {960.0f, 120.0f, 100.0f, 100.0f};
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->data_dynamic.resume_button_state,
    &resume_rect
  );
  
  // Render Settings button
  SDL_FRect settings_rect = {960.0f, 300.0f, 100.0f, 100.0f};
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->data_dynamic.pause_settings_button_state,
    &settings_rect
  );
  
  // Render Main Menu button
  SDL_FRect main_menu_rect = {960.0f, 480.0f, 100.0f, 100.0f};
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->data_dynamic.main_menu_button_state,
    &main_menu_rect
  );
  
  // Update button states based on current selection
  update_pause_button_states(game);
}

void update_pause_button_states(Game *game) {
  // Reset all buttons to idle state first
  game->data_dynamic.resume_button_state = assets.ui.play_button.idle;
  game->data_dynamic.pause_settings_button_state = assets.ui.settings_button.idle;
  game->data_dynamic.main_menu_button_state = assets.ui.exit_button.idle;
  
  // Highlight the selected button
  switch(game->pause_state.current_pause_button) {
    case 0: // Resume
      game->data_dynamic.resume_button_state = assets.ui.play_button.selected;
      break;
    case 1: // Settings
      game->data_dynamic.pause_settings_button_state = assets.ui.settings_button.selected;
      break;
    case 2: // Main Menu
      game->data_dynamic.main_menu_button_state = assets.ui.exit_button.selected;
      break;
  }
}
