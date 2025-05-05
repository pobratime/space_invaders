#include "render_menu.h"
#include "assets/assets.h"
#include <_string.h>

void render_menu(Game *game){

  render_play_button(game);
  render_settins_button(game);
  render_exit_button(game);
  render_title(game);
}

void render_play_button(Game *game){
  SDL_FRect rect = {
    960.0f, 120.0f, 100.0f, 100.0f
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->data_dynamic.play_button_state,
    &rect
  );
}

void render_settins_button(Game *game){
  SDL_FRect rect = {
    960.0f, 300.0f, 100.0f, 100.0f
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->data_dynamic.settings_button_state,
    &rect
  );
}

void render_exit_button(Game *game){
  SDL_FRect rect = {
    960.0f, 480.0f, 100.0f, 100.0f
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ui.bmp_file,
    &game->data_dynamic.exit_button_state,
    &rect
  );
}

void render_title(Game *game){

  SDL_FRect rect = {
    160.0f, 120.0f, 300.0f, 200.0f
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.space,
    NULL,
    &rect
  );

  SDL_FRect rect_2 = {
    160.0f, 340.0f, 500.0f, 200.0f
  };
  SDL_RenderTexture(
    game->renderer,
    assets.ttf.invaders,
    NULL,
    &rect_2
  );
}
