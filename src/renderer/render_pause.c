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
  render_pause_title(game);
}

void render_pause_title(Game *game){
  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;
  
  SDL_FRect rect_g = {
    340.0f * scale_x, 100.0f * scale_y, 400.0f * scale_x, 200 * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.game,
    NULL,
    &rect_g
  );  

  SDL_FRect rect_p = {
    840.0f * scale_x, 100.0f * scale_y, 400.0f * scale_x, 200 * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.paused,
    NULL,
    &rect_p
  );
}

void render_pause_menu(Game *game){
  // Render Resume button  
  float scale_x = game->options_data.x_scale; 
  float scale_y = game->options_data.y_scale;
  
  SDL_FRect resume_rect = {
    500.0f * scale_x, 425.0f * scale_y, 100.0f * scale_x, 100.0f * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->pause_data.resume_button_state,
    &resume_rect
  );

  SDL_FRect resume_text = {
    resume_rect.x + 150.0f * scale_x, resume_rect.y, 300.0f * scale_x, 100.0f * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.resume,
    NULL,
    &resume_text
  );
  
  // Render Settings button
  SDL_FRect settings_rect = {
    500.0f * scale_x, 625.0f * scale_y, 100.0f * scale_x, 100.0f * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->pause_data.settings_button_state,
    &settings_rect
  );
    SDL_FRect settings_text = {
    settings_rect.x + 150.0f * scale_x, settings_rect.y, 300.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.settings_title,
    NULL,
    &settings_text
  );
  // Render Main Menu button
  SDL_FRect main_menu_rect = {
    500.0f * scale_x, 825.0f * scale_y, 100.0f * scale_x, 100.0f * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->pause_data.main_menu_button_state,
    &main_menu_rect
  );
  
  SDL_FRect main_menu_text = {
    main_menu_rect.x + 150.0f * scale_x, main_menu_rect.y, 500.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.main_menu,
    NULL,
    &main_menu_text
  );
}
