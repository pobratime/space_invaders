#include "renderer.h"
#include "assets/assets.h"
#include "render_options.h"
#include "renderer/render_game_over.h"
#include "renderer/render_menu.h"
#include "renderer/render_options.h"
#include "renderer/render_welcome.h"
#include <SDL3/SDL.h>

// Main rendering function which calls subfunctions that render specific parts
// of the game
void render_game(Game *game) {

  switch(game->options_data.current_resolution_int){
    case(1):{
      game->options_data.x_scale = 1680.0f / 1680.0f;
      game->options_data.y_scale = 1050.0f / 1050.0f;
      SDL_SetWindowSize(game->window, 1680.0f, 1050.0f);
      break;
    }
    case(2):{
      game->options_data.x_scale = 1280.0f / 1680.0f;
      game->options_data.y_scale = 800.0f / 1050.0f; 
      SDL_SetWindowSize(game->window, 1280.0f, 800.0f);
      break;
    }
    case(3):{
      game->options_data.x_scale = 1920.0f / 1680.0f;
      game->options_data.y_scale = 1080.0f / 1050.0f;
      SDL_SetWindowSize(game->window, 1920.0f, 1080.0f);
      break;
    }
  }

  // game background is always being rendered
  render_background(game);

  // rendering the game based on the current game state
  switch (game->data_dynamic.state) {
  case (GAME_STATE_MENU): {
    render_menu(game);
    break;
  }
  case (GAME_STATE_PLAYING): {
    render_playing(game);
    break;
  }
  case (GAME_STATE_PAUSED): {
    render_pause(game);
    break;
  }
  case (GAME_STATE_OPTIONS): {
    render_options(game);
    break;
  }
  case (GAME_STATE_GAME_OVER): {
    // render_game_over(game);
    break;
  }
  case (GAME_STATE_WELCOME): {
    // render_welcome(game);
    break;
  }
  }

}

void render_background(Game *game){
  float scale_x = game->options_data.x_scale;
  float scale_y = game->options_data.y_scale;

  SDL_FRect rect1 = {
    0.0f,
    game->data_dynamic.background_y_level,
    1680.0f * scale_x,
    1050.0f * scale_y
  };
  SDL_FRect rect2 = {
    0.0f,
    game->data_dynamic.background_y_level - 1050.0f * scale_y,
    1680.0f * scale_x,
    1050.0f * scale_y
  };

  SDL_RenderTexture(
    game->renderer,
    assets.background.bmp_file,
    &assets.background.rect_1,
    &rect1
  );
  SDL_RenderTexture(
    game->renderer,
    assets.background.bmp_file,
    &assets.background.rect_1,
    &rect2
  );
}
