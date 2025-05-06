#include "render_menu.h"
#include "assets/assets.h"
#include <_string.h>

void render_menu(Game *game){

  render_play_button(game);
  render_settins_button(game);
  render_exit_button(game);
  render_title(game);
  render_feedback_button(game);
}

void render_feedback_button(Game *game){
  float scale_x = game->options_data.x_scale;
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect = {
    960.0f * scale_x, 800.0f * scale_y, 100.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->menu_data.feedback_button_state,
    &rect
  );
  
  SDL_FRect rect_1 = {
    rect.x + 150.0f * scale_x, rect.y, 350.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.feedback,
    NULL,
    &rect_1
  );
}

void render_play_button(Game *game){
  float scale_x = game->options_data.x_scale;
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect = {
    960.0f * scale_x, 200.0f * scale_y, 100.0f * scale_x, 100.0f * scale_y
  };
  SDL_FRect rect_1 = {
    rect.x + 150.0f * scale_x, rect.y, 200.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.play,
    NULL,
    &rect_1
  );

  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->menu_data.play_button_state,
    &rect
  );

}

void render_settins_button(Game *game){  
  float scale_x = game->options_data.x_scale;
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect = {
    960.0f * scale_x, 400.0f * scale_y, 100.0f * scale_x, 100.0f * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->menu_data.settings_button_state,
    &rect
  );  
  
  SDL_FRect rect_1 = {
    rect.x + 150.0f * scale_x, rect.y, 350.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.settings_title,
    NULL,
    &rect_1
  );
}

void render_exit_button(Game *game){
  float scale_x = game->options_data.x_scale;
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect = {
    960.0f * scale_x, 600.0f * scale_y, 100.0f * scale_x , 100.0f * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->menu_data.exit_button_state,
    &rect
  );

  SDL_FRect rect_1 = {
    rect.x + 150.0f * scale_x, rect.y, 200.0f * scale_x, 100.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.ttf.exit,
    NULL,
    &rect_1
  );
}

void render_title(Game *game){
  float scale_x = game->options_data.x_scale;
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect = {
    160.0f * scale_x, 150.0f * scale_y, 500.0f * scale_x, 400.0f * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.space,
    NULL,
    &rect
  );

  SDL_FRect rect_2 = {
    160.0f * scale_x, 500.0f * scale_y, 700.0f * scale_x, 400.0f * scale_y
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.invaders,
    NULL,
    &rect_2
  );
}
