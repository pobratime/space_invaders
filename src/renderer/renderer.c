#include "renderer.h"
#include "assets/assets.h"
#include "renderer/render_game_over.h"
#include "renderer/render_menu.h"
#include "renderer/render_options.h"
#include "renderer/render_welcome.h"
#include <SDL3/SDL.h>

// Main rendering function which calls subfunctions that render specific parts
// of the game
void render_game(Game *game) {

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
    // render_options(game);
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
  SDL_FRect rect1 = {
    0.0f,
    game->data_dynamic.background_y_level,
    1280.0f,
    720.0f
  };
  SDL_FRect rect2 = {
    0.0f,
    game->data_dynamic.background_y_level - 720.0f,
    1280.0f,
    720.0f
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
